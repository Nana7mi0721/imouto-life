
void FUN_00675c40(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if (*(int *)(param_1 + 0x250) == 0) {
    if (param_4 == 0) {
      param_4 = *(int *)(param_1 + 0x254);
    }
    if ((param_4 == 3) || ((param_4 == 2 && ((*(uint *)(param_1 + 0x11c) & 0x20000000) != 0)))) {
      iVar2 = FUN_00675dc0(param_1,param_3);
      if (iVar2 == 0) goto LAB_00675d57;
    }
    else {
      FUN_00673140(param_1,param_3);
    }
LAB_00675d0b:
    if (param_4 != 3) {
      if (param_4 != 2) goto LAB_00675d57;
LAB_00675d15:
      if ((*(uint *)(param_1 + 0x11c) & 0x20000000) == 0) goto LAB_00675d57;
    }
    iVar2 = *(int *)(param_1 + 0x298);
    if (iVar2 != 0) {
      if (iVar2 == 1) goto LAB_00675d57;
      if (iVar2 == 2) {
        *(undefined4 *)(param_1 + 0x298) = 1;
        FUN_00668b90(param_1,s_no_space_in_chunk_cache_00a0d0a0);
        goto LAB_00675d57;
      }
      *(int *)(param_1 + 0x298) = iVar2 + -1;
    }
    FUN_00672dd0(param_1,param_2,param_1 + 0x2a0,1);
  }
  else {
    iVar2 = FUN_00675dc0(param_1,param_3);
    if (iVar2 == 0) goto LAB_00675d57;
    iVar2 = (**(code **)(param_1 + 0x250))(param_1,param_1 + 0x2a0);
    if (iVar2 < 0) {
      FUN_00668a30(param_1,s_error_in_user_chunk_00a0d16c);
      goto LAB_00675d0b;
    }
    if (iVar2 == 0) {
      if (1 < param_4) goto LAB_00675d0b;
      if (*(int *)(param_1 + 0x254) < 2) {
        FUN_00668b30(param_1,s_Saving_unknown_chunk__00a0d154);
        FUN_006689d0(param_1,s_forcing_save_of_an_unhandled_chu_00a0d108);
      }
      goto LAB_00675d15;
    }
  }
  bVar1 = true;
LAB_00675d57:
  if (*(int *)(param_1 + 0x2a8) != 0) {
    FUN_0066cb60(param_1,*(int *)(param_1 + 0x2a8));
  }
  *(undefined4 *)(param_1 + 0x2a8) = 0;
  if ((!bVar1) && ((*(uint *)(param_1 + 0x11c) & 0x20000000) == 0)) {
    FUN_00668a30(param_1,s_unhandled_critical_chunk_00a0d0ec);
  }
  return;
}

