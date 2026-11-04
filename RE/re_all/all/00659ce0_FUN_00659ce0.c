
int FUN_00659ce0(int param_1,int param_2,double *param_3)

{
  int iVar1;
  uint local_10;
  uint local_c;
  
  if ((*(uint *)(param_1 + 0xc) & 0x80000) == 0) {
    param_2 = *(int *)(param_2 + 0x10);
    if ((*(uint *)(param_1 + 0xc) & 0x80) != 0) {
      FUN_0065a600(&param_2);
    }
    iVar1 = FUN_006558d0(param_1,param_2,0,8,&local_10);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  else {
    local_10 = *(uint *)(param_2 + 0x10);
    local_c = *(uint *)(param_2 + 0x14);
  }
  if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
    FUN_0065a6c0(&local_10,2);
  }
  if (local_10 == 0) {
    *(undefined4 *)param_3 = 0;
    *(undefined4 *)((int)param_3 + 4) = 0;
    return 0;
  }
  *param_3 = (double)local_10 / (double)local_c;
  return 0;
}

