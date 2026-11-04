
/* WARNING: Removing unreachable block (ram,0x005d35e0) */

undefined4 FUN_005d34c0(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 local_4;
  
  iVar1 = *param_2;
  local_4 = 0;
  uStack_18 = (undefined4 *)0x5d34d8;
  iStack_20 = FUN_0050e7d0();
  uStack_18 = &local_4;
  iStack_1c = iVar1;
  for (iVar1 = (**(code **)(*DAT_00f3a044 + 0x2c))(DAT_00f3a044,0,1,param_1); iVar1 != 0;
      iVar1 = (**(code **)(*DAT_00f3a044 + 0x2c))(DAT_00f3a044,0,1,param_1,uVar2,iVar1,&iStack_20))
  {
    if (unaff_EBP != 0) goto LAB_005d3549;
    *param_2 = *param_2 + -1;
    if (*param_2 == 0) goto LAB_005d3537;
    iVar1 = *param_2;
    uVar2 = FUN_0050e7d0();
  }
  iVar1 = *param_2;
  if (iVar1 != 0) {
    uVar2 = FUN_0050e7d0();
    for (iVar1 = (**(code **)(*DAT_00f3a044 + 0x2c))
                           (DAT_00f3a044,0,1,0x50,uVar2,iVar1,(int)register0x00000010 + -0x14);
        iVar1 != 0;
        iVar1 = (**(code **)(*DAT_00f3a044 + 0x2c))
                          (DAT_00f3a044,0,1,0x50,uVar2,iVar1,(int)register0x00000010 + -0x14)) {
      if (unaff_EBP != 0) {
LAB_005d3549:
        *unaff_ESI = 0;
        return 0xffffffff;
      }
      *param_2 = *param_2 + -1;
      if (*param_2 == 0) goto LAB_005d3537;
      iVar1 = *param_2;
      uVar2 = FUN_0050e7d0();
    }
    if (*param_2 != 0) {
      return 0;
    }
  }
LAB_005d3537:
  *unaff_ESI = 0;
  return 0;
}

