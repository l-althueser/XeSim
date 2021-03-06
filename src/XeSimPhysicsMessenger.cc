#include <G4Geantino.hh>
#include <G4ThreeVector.hh>
#include <G4ParticleTable.hh>
#include <G4UIdirectory.hh>
#include <G4UIcmdWithoutParameter.hh>
#include <G4UIcmdWithAString.hh>
#include <G4UIcmdWithADoubleAndUnit.hh>
#include <G4UIcmdWith3Vector.hh>
#include <G4UIcmdWith3VectorAndUnit.hh>
#include <G4UIcmdWithAnInteger.hh>
#include <G4UIcmdWithADouble.hh>
#include <G4UIcmdWithABool.hh>
#include <G4Tokenizer.hh>
#include <G4ios.hh>
#include <fstream>
#include <iomanip>

#include "XeSimPhysicsMessenger.hh"
#include "XeSimPhysicsList.hh"

XeSimPhysicsMessenger::XeSimPhysicsMessenger(XeSimPhysicsList *pPhysicsList):
  m_pPhysicsList(pPhysicsList)
{
  // create directory
  m_pDirectory = new G4UIdirectory("/run/physics/");
  m_pDirectory->SetGuidance("PhysicsList control commands.");

  // set which EM model to use
  m_pEMlowEnergyModelCmd = new G4UIcmdWithAString("/run/physics/setEMlowEnergyModel", this);
  m_pEMlowEnergyModelCmd->SetGuidance("Choose low energy EM model from:");
  m_pEMlowEnergyModelCmd->SetGuidance("<emstandard = no low E> <emlivermore> <empenelope> <old>");
  m_pEMlowEnergyModelCmd->SetDefaultValue("emlivermore");
  m_pEMlowEnergyModelCmd->AvailableForStates(G4State_PreInit);

  // set which Hadronic model to use
  m_pHadronicModelCmd = new G4UIcmdWithAString("/run/physics/setHadronicModel", this);
  m_pHadronicModelCmd->SetGuidance("Choose hadronic model from:");
  m_pHadronicModelCmd->SetGuidance("<custom = standard Xenon100> <QGSP_BERT> <QGSP_BERT_HP>");
  m_pHadronicModelCmd->SetDefaultValue("custom");
  m_pHadronicModelCmd->AvailableForStates(G4State_PreInit);
	
	  // switch Cerenkov radiation on - or - off
  m_pCerenkovCmd = new G4UIcmdWithABool("/run/physics/setCerenkov", this);
  m_pCerenkovCmd->SetGuidance("Switch Cerenkov radiation on (=true) or off (=false)");
  m_pCerenkovCmd->SetDefaultValue(false);
  m_pCerenkovCmd->AvailableForStates(G4State_PreInit);
}

XeSimPhysicsMessenger::~XeSimPhysicsMessenger()
{
  delete m_pDirectory;
}

void
XeSimPhysicsMessenger::SetNewValue(G4UIcommand * command, G4String newValues)
{
  if(command == m_pEMlowEnergyModelCmd)
    m_pPhysicsList->SetEMlowEnergyModel(newValues);

  if(command == m_pHadronicModelCmd)
    m_pPhysicsList->SetHadronicModel(newValues);
    
  if(command == m_pCerenkovCmd)
    m_pPhysicsList->SetCerenkov(m_pCerenkovCmd->GetNewBoolValue(newValues));
}

