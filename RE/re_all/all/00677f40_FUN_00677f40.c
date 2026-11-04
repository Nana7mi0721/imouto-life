
void FUN_00677f40(int param_1,undefined4 param_2,undefined1 *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_460;
  undefined1 auStack_45f [83];
  undefined1 local_40c [8];
  int local_404;
  
  if (param_3 == (undefined1 *)0x0) {
    FUN_00668620(param_1,s_No_profile_for_iCCP_chunk_00a0d574);
  }
  bVar1 = param_3[3];
  uVar4 = CONCAT31(CONCAT21(CONCAT11(*param_3,param_3[1]),param_3[2]),bVar1);
  if (uVar4 < 0x84) {
    FUN_00668620(param_1,s_ICC_profile_too_short_00a0d55c);
  }
  if ((3 < (byte)param_3[8]) && ((bVar1 & 3) != 0)) {
    FUN_00668620(param_1,s_ICC_profile_length_invalid__not_a_00a0d528);
  }
  if (uVar4 != CONCAT31(CONCAT21(CONCAT11(*param_3,param_3[1]),param_3[2]),param_3[3])) {
    FUN_00668620(param_1,s_Profile_length_does_not_match_pr_00a0d500);
  }
  iVar2 = FUN_006782a0(param_1,param_2,&local_460);
  if (iVar2 == 0) {
    FUN_00668620(param_1,s_iCCP__invalid_keyword_00a0d4e8);
  }
  auStack_45f[iVar2] = 0;
  iVar2 = iVar2 + 2;
  FUN_006780a0(local_40c,param_3,uVar4);
  iVar3 = FUN_006780c0(param_1,0x69434350,local_40c,iVar2);
  if (iVar3 != 0) {
    FUN_00668620(param_1,*(undefined4 *)(param_1 + 0x9c));
  }
  FUN_00677300(param_1,0x69434350,local_404 + iVar2);
  FUN_00677370(param_1,&local_460,iVar2);
  FUN_00678240(param_1,local_40c);
  FUN_006773b0(param_1);
  return;
}

