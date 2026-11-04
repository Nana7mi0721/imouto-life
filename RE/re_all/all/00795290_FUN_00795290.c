
void FUN_00795290(ushort *param_1,int *param_2,ushort *param_3,ushort *param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)(((((param_3[2] <= param_1[5] && param_3[1] <= param_1[4]) &&
                   param_1[2] <= param_4[2]) && param_1[1] <= param_4[1]) && *param_3 <= param_1[3])
                && *param_1 <= *param_4);
  iVar1 = *(int *)(param_1 + 6);
  if (((int)(-uVar2 | uVar2) >> 0x1f & 1U) != 0) {
    while (iVar1 < 0) {
      FUN_00795290(param_1 + 8,param_2,param_3,param_4);
      if (*(int *)(param_1 + 0xe) < 0) {
        param_1 = param_1 + 8 + *(int *)(param_1 + 0xe) * -8;
      }
      else {
        param_1 = param_1 + 0x10;
      }
      uVar2 = (uint)(((((param_3[2] <= param_1[5] && param_3[1] <= param_1[4]) &&
                       param_1[2] <= param_4[2]) && param_1[1] <= param_4[1]) &&
                     *param_3 <= param_1[3]) && *param_1 <= *param_4);
      iVar1 = *(int *)(param_1 + 6);
      if (((int)(-uVar2 | uVar2) >> 0x1f & 1U) == 0) {
        return;
      }
    }
    (**(code **)(*param_2 + 4))
              ((int)*(uint *)(param_1 + 6) >> 0x15,*(uint *)(param_1 + 6) & 0x1fffff);
  }
  return;
}

