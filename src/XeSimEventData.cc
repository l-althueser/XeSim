#include "XeSimEventData.hh"

XeSimEventData::XeSimEventData() {
	m_iEventId = 0;
	m_iNbPhotoDetHits = 0;
    m_pPhotoDetHits = new vector<int>;
    m_pPhotoDetHitID = new vector<int>;
	m_pPhotoDetHitTime = new vector<double>;
	m_pPhotoDetHitEnergy = new vector<float>;
	m_pPhotoDetHitTheta = new vector<float>;
	m_pPhotoDetHitPhi = new vector<float>;
	//m_pPhotoDetHitVolumeName = new vector<string>;
	m_pPhotoDetHitX = new vector<float>;
	m_pPhotoDetHitY = new vector<float>;
	m_pPhotoDetHitZ = new vector<float>;
    
	m_fTotalEnergyDeposited = 0.;
	m_iNbSteps = 0;

	m_pTrackId = new vector<int>;
	m_pParentId = new vector<int>;
	m_pParticleType = new vector<string>;
	m_pParentType = new vector<string>;
	m_pCreatorProcess = new vector<string>;
	m_pDepositingProcess = new vector<string>;
	m_pX = new vector<float>;
	m_pY = new vector<float>;
	m_pZ = new vector<float>;
	m_pEnergyDeposited = new vector<float>;
	m_pKineticEnergy = new vector<float>;
    
	m_pTime = new vector<double>;

	m_pPrimaryParticleType = new vector<string>;
	m_fPrimaryEnergy = 0.;
	m_fPrimaryX = 0.;
	m_fPrimaryY = 0.;
	m_fPrimaryZ = 0.;
    m_fPrimaryVolume = "";
}

XeSimEventData::~XeSimEventData() {
	delete m_pPhotoDetHits;
    delete m_pPhotoDetHitID;
    delete m_pPhotoDetHitTime;
    delete m_pPhotoDetHitEnergy;
    delete m_pPhotoDetHitTheta;
    delete m_pPhotoDetHitPhi;
    delete m_pPhotoDetHitX;
    delete m_pPhotoDetHitY;
    delete m_pPhotoDetHitZ;
    
	delete m_pTrackId;
	delete m_pParentId;
	delete m_pParticleType;
	delete m_pParentType;
	delete m_pCreatorProcess;
	delete m_pDepositingProcess;
	delete m_pX;
	delete m_pY;
	delete m_pZ;
	delete m_pEnergyDeposited;
	delete m_pKineticEnergy;
	delete m_pTime;

	delete m_pPrimaryParticleType;
}

void XeSimEventData::Clear() {
	m_iEventId = 0;
    m_iNbPhotoDetHits = 0;
    m_pPhotoDetHits->clear();
    m_pPhotoDetHitID->clear();
    m_pPhotoDetHitTime->clear();
    m_pPhotoDetHitEnergy->clear();
    m_pPhotoDetHitTheta->clear();
    m_pPhotoDetHitPhi->clear();
    m_pPhotoDetHitX->clear();
    m_pPhotoDetHitY->clear();
    m_pPhotoDetHitZ->clear();
    
	m_fTotalEnergyDeposited = 0.0;
	m_iNbSteps = 0;

	m_pTrackId->clear();
	m_pParentId->clear();
	m_pParticleType->clear();
	m_pParentType->clear();
	m_pCreatorProcess->clear();
	m_pDepositingProcess->clear();
	m_pX->clear();
	m_pY->clear();
	m_pZ->clear();
	m_pEnergyDeposited->clear();
	m_pKineticEnergy->clear();
	m_pTime->clear();

	m_pPrimaryParticleType->clear();
	m_fPrimaryEnergy = 0.;
	m_fPrimaryX = 0.;
	m_fPrimaryY = 0.;
	m_fPrimaryZ = 0.;	
    m_fPrimaryVolume = "";
}

