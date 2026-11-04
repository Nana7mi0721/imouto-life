
undefined4 FUN_005d2a20(undefined4 param_1,int *param_2,uint *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uStack_4;
  
  iVar2 = param_4;
  piVar1 = param_2;
  if (*param_2 == 1) {
    *param_3 = 0;
    return 0;
  }
  param_2 = (int *)0x0;
  while( true ) {
    iVar3 = (**(code **)(*DAT_00f3a070 + 0x78))(DAT_00f3a070,param_1,*piVar1,&param_2);
    if ((iVar3 == 0) && (param_2 != (int *)0x0)) break;
    if (iVar2 != 0) goto LAB_005d2aee;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 1) {
      *param_3 = 0;
      return 0;
    }
  }
  if (*piVar1 != 1) {
    uStack_4 = 0;
    while( true ) {
      iVar3 = (**(code **)(*DAT_00f3a070 + 0x78))(DAT_00f3a070,0x37,*piVar1,&uStack_4);
      if ((iVar3 == 0) && (uStack_4 != 0)) break;
      if (iVar2 != 0) {
LAB_005d2aee:
        *param_3 = 0;
        return 0xffffffff;
      }
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 1) {
        *param_3 = 0;
        return 0;
      }
    }
    if (*piVar1 != 1) {
      if (param_2 <= uStack_4) {
        uStack_4 = (uint)param_2;
      }
      if (uStack_4 - 1 < *param_3) {
        *param_3 = uStack_4 - 1;
      }
      return 0;
    }
  }
  *param_3 = 0;
  return 0;
}

