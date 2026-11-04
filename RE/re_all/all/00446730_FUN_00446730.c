
/* WARNING: Removing unreachable block (ram,0x00446c55) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00446730(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int local_18;
  undefined4 local_c;
  int local_8;
  
  if ((DAT_00a1fba0 & 1) == 0) {
    DAT_00a1fba0 = DAT_00a1fba0 | 1;
    _DAT_00a1fb9c = (int)DAT_00a18acc;
  }
  local_8 = 0;
  do {
    iVar1 = FUN_004d25e0();
    if (iVar1 <= local_8) {
      if ((*(char *)(param_1 + 0xc0) != '\0') && (DAT_00a14581 == '\0')) {
        FUN_004ce1d0();
      }
      *(undefined1 *)(param_1 + 0xc0) = 0;
      return;
    }
    if (DAT_00a18c71 != '\0') {
      iVar1 = FUN_004d2620(local_8);
      *(undefined2 *)(iVar1 + 0x5a) = *(undefined2 *)(param_1 + 0x5a);
    }
    piVar2 = (int *)FUN_004ce990(local_8);
    if (*piVar2 == -1) {
      uVar9 = 0;
      FUN_004d2620(local_8);
      puVar3 = (undefined1 *)FUN_004cd7c0(uVar9);
      *puVar3 = DAT_00a18ab4;
    }
    else {
      piVar2 = (int *)FUN_004ce990(local_8);
      if (*piVar2 < -1) {
        uVar9 = 0;
        FUN_004d2620(local_8);
        puVar3 = (undefined1 *)FUN_004cd7c0(uVar9);
        *puVar3 = 0xff;
      }
      else {
        puVar3 = (undefined1 *)FUN_004ce990(local_8);
        uVar9 = 0;
        FUN_004d2620(local_8);
        puVar4 = (undefined1 *)FUN_004cd7c0(uVar9);
        *puVar4 = *puVar3;
      }
    }
    if ((DAT_00a18c71 != '\0') && (*(char *)(param_1 + 0xc0) != '\0')) {
      if (DAT_00a14581 == '\0') {
        if (DAT_00a18acc < 1) {
          local_18 = 1;
        }
        else {
          local_18 = (int)DAT_00a18acc;
        }
        puVar5 = (undefined4 *)FUN_004ce990((local_8 + 1) * local_18);
        local_c = *puVar5;
      }
      else {
        local_c = *(undefined4 *)(param_1 + 0x14c);
      }
      switch(local_c) {
      case 1:
        uVar9 = 1;
        FUN_004d2620(local_8);
        FUN_00478c20(uVar9);
        break;
      case 2:
        uVar9 = 1;
        FUN_004d2620(local_8);
        FUN_00443aa0(uVar9);
        break;
      case 3:
        uVar9 = 1;
        FUN_004d2620(local_8);
        FUN_00478ee0(uVar9);
        break;
      case 4:
        uVar9 = 1;
        FUN_004d2620(local_8);
        FUN_00478a70(uVar9);
        break;
      case 6:
        uVar9 = 1;
        FUN_004d2620(local_8);
        FUN_00478b00(uVar9);
        break;
      case 7:
        uVar9 = 1;
        FUN_004d2620(local_8);
        FUN_004791a0(uVar9);
        break;
      case 8:
        uVar9 = 1;
        FUN_004d2620(local_8);
        FUN_00478b90(uVar9);
        break;
      case 9:
        uVar9 = 1;
        FUN_004d2620(local_8);
        FUN_00479460(uVar9);
      }
    }
    FUN_004d2620(local_8);
    FUN_00443270();
    if (DAT_00a180f4 != '\0') {
      iVar1 = FUN_004d2620(local_8);
      if (-1 < *(int *)(iVar1 + 0x28)) {
        iVar1 = FUN_004d2620(local_8);
        iVar6 = FUN_0047a490();
        if (*(int *)(iVar1 + 0x28) < iVar6 * 2) goto LAB_00446b17;
      }
      iVar1 = FUN_004d2620(local_8);
      iVar6 = FUN_004d2620(local_8);
      if (*(int *)(iVar1 + 0x38) == DAT_0084b264 * 2 * *(int *)(iVar6 + 0x28)) {
        iVar1 = FUN_004d2620(local_8);
        iVar6 = FUN_0047a490();
        iVar1 = *(int *)(iVar1 + 0x28);
        iVar7 = FUN_0047a490();
        iVar8 = FUN_004d2620(local_8);
        *(int *)(iVar8 + 0x28) = (iVar1 + iVar6 * 2) % (iVar7 << 1);
        iVar1 = FUN_004d2620(local_8);
        iVar7 = DAT_0084b264 * 2;
        iVar1 = *(int *)(iVar1 + 0x28);
        iVar6 = FUN_004d2620(local_8);
        *(int *)(iVar6 + 0x38) = iVar7 * iVar1;
      }
    }
LAB_00446b17:
    if (DAT_00a180f5 != '\0') {
      iVar1 = FUN_004d2620(local_8);
      if (-1 < *(int *)(iVar1 + 0x2c)) {
        iVar1 = FUN_004d2620(local_8);
        iVar6 = FUN_0047a4b0();
        if (*(int *)(iVar1 + 0x2c) < iVar6 * 2) goto LAB_00446769;
      }
      iVar1 = FUN_004d2620(local_8);
      iVar6 = FUN_004d2620(local_8);
      if (*(int *)(iVar1 + 0x3c) == DAT_0084b264 * 2 * *(int *)(iVar6 + 0x2c)) {
        iVar1 = FUN_004d2620(local_8);
        iVar6 = FUN_0047a4b0();
        iVar1 = *(int *)(iVar1 + 0x2c);
        iVar7 = FUN_0047a4b0();
        iVar8 = FUN_004d2620(local_8);
        *(int *)(iVar8 + 0x2c) = (iVar1 + iVar6 * 2) % (iVar7 << 1);
        iVar1 = FUN_004d2620(local_8);
        iVar7 = DAT_0084b264 * 2;
        iVar1 = *(int *)(iVar1 + 0x2c);
        iVar6 = FUN_004d2620(local_8);
        *(int *)(iVar6 + 0x3c) = iVar7 * iVar1;
      }
    }
LAB_00446769:
    local_8 = local_8 + 1;
  } while( true );
}

