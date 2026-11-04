
undefined4 FUN_005b8ce0(int *param_1,int param_2,int *param_3,undefined4 *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 local_7c;
  undefined4 *puStack_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_60;
  int iStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_34;
  int iStack_30;
  int local_2c;
  int iStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_4;
  
  local_7c = 0;
  FUN_00568ca0();
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  (**(code **)(*param_1 + 0x28))(param_1,&local_2c);
  puStack_78 = (undefined4 *)FUN_005b85a0(uStack_24);
  local_7c = iStack_30;
  if (0 < param_2) {
    FUN_005185c0(iStack_34,iStack_30,param_2,(int)register0x00000010 + -0x80,&local_7c);
  }
  if (param_3 == (int *)0x0) {
    iVar2 = 0;
    iVar3 = 0;
    iStack_74 = iStack_34;
    iStack_70 = local_7c;
  }
  else {
    iVar2 = *param_3;
    iVar3 = param_3[1];
    iStack_74 = param_3[2];
    iStack_70 = param_3[3];
  }
  iStack_74 = iStack_74 - iVar2;
  iStack_70 = iStack_70 - iVar3;
  *param_5 = 0;
  if (((iStack_20 != 1) || (local_2c != 1)) || (iStack_28 != 1)) {
    FUN_0056d380(&iStack_60,0,0x2c);
    iStack_60 = iStack_34;
    uStack_44 = 0;
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_48 = 0;
    uStack_50 = uStack_24;
    iStack_5c = local_7c;
    uStack_58 = 1;
    uStack_54 = 1;
    uStack_4c = 1;
    iVar1 = FUN_005d4ee0(&iStack_60,0,(int)register0x00000010 + -0x84,0);
    if (iVar1 < 0) {
      puVar6 = &DAT_007fd3c4;
      goto LAB_005b8ee7;
    }
    FUN_005d2e50(unaff_EBP,0,iStack_4,local_2c * (int)param_1 + param_2,uStack_24);
  }
  FUN_0056d380(&iStack_60,0,0x2c);
  uStack_50 = uStack_24;
  uStack_40 = 0;
  uStack_48 = 0;
  uStack_44 = 3;
  iStack_60 = iStack_34;
  iStack_5c = local_7c;
  uStack_3c = 0x20000;
  uStack_58 = 1;
  uStack_54 = 1;
  uStack_4c = 1;
  iVar1 = FUN_005d4ee0(&iStack_60,0,param_5,0);
  if (iVar1 < 0) {
    puVar6 = &DAT_007fd384;
  }
  else {
    iVar1 = unaff_EBP;
    if (unaff_EBP == 0) {
      iVar1 = iStack_4;
    }
    FUN_005d2db0(*param_5,iVar1);
    iVar1 = FUN_005d2c10(*param_5,0,1,0,&iStack_6c);
    if (-1 < iVar1) {
      if (unaff_EBP != 0) {
        FUN_005d1ee0(unaff_EBP);
      }
      puVar4 = puStack_78;
      puVar5 = param_4;
      for (iVar1 = 0x10a; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      param_4[0x10a] = iStack_74;
      param_4[0x10b] = iStack_70;
      param_4[0x10c] = iStack_68;
      param_4[0x10d] = iStack_68 * iVar3 + (uint)*(byte *)(puStack_78 + 1) * iVar2 + iStack_6c;
      param_4[0x10e] = 0;
      param_4[0x10f] = 0;
      return 0;
    }
    puVar6 = &DAT_007fd340;
  }
LAB_005b8ee7:
  FUN_0056bb10(puVar6);
  if (*param_5 != 0) {
    FUN_005d1ee0(*param_5);
    *param_5 = 0;
  }
  if (unaff_EBP != 0) {
    FUN_005d1ee0(unaff_EBP);
  }
  return 0xffffffff;
}

