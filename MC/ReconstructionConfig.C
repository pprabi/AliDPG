/*
 * AliDPG - ALICE Experiment Data Preparation Group
 * Reconstruction steering script
 *
 */

/*****************************************************************/
/*****************************************************************/
/*****************************************************************/

enum EReconstruction_t {
  kReconstructionDefault,
  kReconstructionCustom,
  kNReconstructions
};

const Char_t *ReconstructionName[kNReconstructions] = {
  "Default",
  "Custom"
};

/*****************************************************************/

ReconstructionConfig(AliReconstruction &rec, EReconstruction_t tag, Int_t run)
{

  switch(tag) {

    // Default
  case kReconstructionDefault:
    //
    //    // set OCDB snapshot mode
    //    AliCDBManager *man = AliCDBManager::Instance();
    //    man->SetDefaultStorage("alien://Folder=/alice/data/2015/OCDB");
    //    man->SetRun(run);
    //    man->SetSnapshotMode("OCDBrec.root");
    rec.SetCDBSnapshotMode("OCDBrec.root");
    //
    rec.SetCleanESD(kFALSE);
    rec.SetStopOnError(kFALSE);
    rec.SetWriteESDfriend();
    rec.SetWriteAlignmentData();
    rec.SetFractionFriends(.1);
    rec.SetRunPlaneEff(kTRUE);
    rec.SetUseTrackingErrorsForAlignment("ITS");
    //
    rec.SetRunQA(":");
    //
    return;
    
    // Custom
  case kReconstructionCustom:
    if ((gROOT->LoadMacro("ReconstructionCustom.C")) != 0) {
      printf("ERROR: cannot find ReconstructionCustom.C\n");
      abort();
      return;
    }
    ReconstructionCustom(rec, run);
    return;

  }  

}

/*** ITS ****************************************************/

ReconstructionConfigITS(AliReconstruction &rec, Int_t run)
{
  //  rec.SetSpecificStorage("ITS/Align/Data", Residual);
  //  rec.SetSpecificStorage("ITS/Calib/SPDSparseDead", Residual);
}

/*** TPC ****************************************************/

ReconstructionConfigTPC(AliReconstruction &rec, Int_t run)
{
  //  rec.SetSpecificStorage("TPC/Calib/Parameters",   Residual);
  //  rec.SetSpecificStorage("TPC/Calib/ClusterParam", Residual);
  //  rec.SetSpecificStorage("TPC/Calib/RecoParam",    Full);
  //  rec.SetSpecificStorage("TPC/Align/Data",         Residual);
  //  rec.SetSpecificStorage("TPC/Calib/TimeGain",     Residual);
  //  rec.SetSpecificStorage("TPC/Calib/TimeDrift",    Residual);
  //  rec.SetSpecificStorage("TPC/Calib/Correction",   Residual);
}

/*** TRD ****************************************************/

ReconstructionConfigTRD(AliReconstruction &rec, Int_t run)
{
}

/*** TOF ****************************************************/

ReconstructionConfigTOF(AliReconstruction &rec, Int_t run)
{
}

/*** HMPID ****************************************************/

ReconstructionConfigHMPID(AliReconstruction &rec, Int_t run)
{
}

/*** PHOS ****************************************************/

ReconstructionConfigPHOS(AliReconstruction &rec, Int_t run)
{
}

/*** EMCAL ****************************************************/

ReconstructionConfigEMCAL(AliReconstruction &rec, Int_t run)
{
}

/*** MUON ****************************************************/

ReconstructionConfigMUON(AliReconstruction &rec, Int_t run)
{
  //  rec.SetSpecificStorage("MUON/Align/Data", Residual); 
}

/*** ZDC ****************************************************/

ReconstructionConfigZDC(AliReconstruction &rec, Int_t run)
{
  //  rec.SetSpecificStorage("ZDC/Align/Data", Ideal);
  //  rec.SetSpecificStorage("ZDC/Calib/Pedestals", Ideal); // only for PbPb ?
}