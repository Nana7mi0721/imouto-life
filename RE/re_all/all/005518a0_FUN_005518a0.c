
undefined4
FUN_005518a0(int *param_1,uint param_2,uint param_3,int *param_4,uint *param_5,undefined4 *param_6,
            int *param_7)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (*param_1 == 0) {
    return 0xffffffff;
  }
  if ((DAT_00a83c64 == 0) &&
     (iVar2 = FUN_0057e7d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7), iVar2 != 2)) {
    if (iVar2 == -1) {
      return 0xffffffff;
    }
    return 0;
  }
  uVar3 = param_2 / *(ushort *)(param_1 + 0xf);
  uVar4 = param_3 / *(ushort *)(param_1 + 0xf);
  uVar1 = param_1[0xb];
  if (uVar1 < uVar4 + uVar3) {
    *param_4 = *(int *)param_1[0x13] + param_2;
    iVar2 = uVar1 - uVar3;
    *param_5 = (uint)*(ushort *)(param_1 + 0xf) * iVar2;
    *param_6 = *(undefined4 *)param_1[0x13];
    *param_7 = (uVar4 - iVar2) * (uint)*(ushort *)(param_1 + 0xf);
    return 0;
  }
  *param_4 = *(int *)param_1[0x13] + param_2;
  *param_5 = param_3;
  *param_6 = 0;
  *param_7 = 0;
  return 0;
}

