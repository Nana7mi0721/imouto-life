
undefined4 __thiscall FUN_0044ab10(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_10;
  int local_8;
  
  if (*(int *)(param_1 + 0x1658) != -1) {
    if (*DAT_00a16694 == '\0') {
      for (local_10 = 2; -1 < local_10; local_10 = local_10 + -1) {
        iVar1 = FUN_0047a4d0(param_2,param_3,local_10);
        iVar3 = FUN_0047a4d0(param_2 + -1,param_3,local_10);
        iVar4 = FUN_0047a4d0(param_2 + 1,param_3,local_10);
        iVar5 = FUN_0047a4d0(param_2,param_3 + 1,local_10);
        iVar6 = FUN_0047a4d0(param_2 + -1,param_3 + 1,local_10);
        iVar7 = FUN_0047a4d0(param_2 + 1,param_3 + 1,local_10);
        if (((((iVar1 != -1) && (iVar3 != -1)) && (iVar4 != -1)) &&
            (((iVar5 != -1 && (iVar6 != -1)) && (iVar7 != -1)))) &&
           (((puVar2 = (uint *)FUN_004ce990(iVar1), (*puVar2 & 0x80) != 0 ||
             (puVar2 = (uint *)FUN_004ce990(iVar3), (*puVar2 & 0x80) != 0)) ||
            ((puVar2 = (uint *)FUN_004ce990(iVar4), (*puVar2 & 0x80) != 0 ||
             (((puVar2 = (uint *)FUN_004ce990(iVar5), (*puVar2 & 0x80) != 0 ||
               (puVar2 = (uint *)FUN_004ce990(iVar6), (*puVar2 & 0x80) != 0)) ||
              (puVar2 = (uint *)FUN_004ce990(iVar7), (*puVar2 & 0x80) != 0)))))))) {
          return 1;
        }
      }
    }
    else {
      for (local_8 = 2; -1 < local_8; local_8 = local_8 + -1) {
        iVar1 = FUN_0047a4d0(param_2,param_3,local_8);
        if ((iVar1 != -1) && (puVar2 = (uint *)FUN_004ce990(iVar1), (*puVar2 & 0x80) != 0)) {
          return 1;
        }
      }
    }
  }
  return 0;
}

