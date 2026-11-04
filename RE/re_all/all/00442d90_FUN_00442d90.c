
undefined4 __thiscall FUN_00442d90(int param_1,int param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_18;
  
  local_18 = 0;
  do {
    iVar4 = FUN_004d29a0();
    if (iVar4 <= local_18) {
      return 1;
    }
    iVar4 = FUN_004d2a00(local_18);
    bVar2 = false;
    if (*(char *)(iVar4 + 0xb9) == '\0') {
LAB_00442e84:
      iVar5 = FUN_0047a4b0();
      iVar1 = *(int *)(iVar4 + 0x2c);
      iVar6 = FUN_0047a4b0();
      iVar7 = FUN_0047a4b0();
      if ((iVar1 + iVar5 * 2) % (iVar6 << 1) == param_3 % (iVar7 << 1)) {
        bVar2 = true;
      }
    }
    else {
      iVar5 = FUN_0047a4b0();
      iVar1 = *(int *)(iVar4 + 0x2c);
      iVar6 = FUN_0047a4b0();
      iVar7 = FUN_0047a4b0();
      if ((iVar1 + iVar5 * 2) % (iVar6 << 1) != param_3 - (int)(1 % (longlong)(iVar7 << 1))) {
        iVar5 = FUN_0047a4b0();
        iVar1 = *(int *)(iVar4 + 0x2c);
        iVar6 = FUN_0047a4b0();
        iVar7 = FUN_0047a4b0();
        if ((iVar1 + iVar5 * 2) % (iVar6 << 1) != param_3 % (iVar7 << 1)) goto LAB_00442e84;
      }
      bVar2 = true;
    }
    if (*(int *)(iVar4 + 0x24) != *(int *)(param_1 + 0x24)) {
      iVar5 = FUN_0047a490();
      iVar1 = *(int *)(iVar4 + 0x28);
      iVar6 = FUN_0047a490();
      iVar7 = FUN_0047a490();
      iVar8 = FUN_0047a490();
      if ((iVar1 + iVar5 * 2) % (iVar6 << 1) != (param_2 + -1 + iVar7 * 2) % (iVar8 << 1)) {
        iVar5 = FUN_0047a490();
        iVar1 = *(int *)(iVar4 + 0x28);
        iVar6 = FUN_0047a490();
        if ((iVar1 + iVar5 * 2) % (iVar6 << 1) != param_2) goto LAB_00442db4;
      }
      if ((bVar2) && (*(char *)(iVar4 + 0x53) == '\0')) {
        if (*(char *)(param_1 + 0x54) == '\0') {
          return 0;
        }
        cVar3 = operator!=<>(iVar4 + 8,&DAT_007ce95b);
        if ((cVar3 != '\0') || (*(int *)(iVar4 + 0x40) != -1)) {
          return 0;
        }
      }
    }
LAB_00442db4:
    local_18 = local_18 + 1;
  } while( true );
}

