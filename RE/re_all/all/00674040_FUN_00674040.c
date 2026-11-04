
int FUN_00674040(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2b8);
  if (iVar1 != 0) {
    if (param_2 <= *(uint *)(param_1 + 700)) {
      return iVar1;
    }
    *(undefined4 *)(param_1 + 0x2b8) = 0;
    *(undefined4 *)(param_1 + 700) = 0;
    FUN_0066cb60(param_1,iVar1);
  }
  iVar1 = FUN_0066c990(param_1,param_2);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x2b8) = iVar1;
    *(uint *)(param_1 + 700) = param_2;
    return iVar1;
  }
  if (param_3 < 2) {
    if (param_3 != 0) {
      FUN_00668b30();
      return 0;
    }
    FUN_00668a30(param_1,s_insufficient_memory_to_read_chun_00a0cec4);
  }
  return 0;
}

