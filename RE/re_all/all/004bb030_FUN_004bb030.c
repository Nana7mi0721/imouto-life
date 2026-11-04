
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004bb030(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  int local_a4;
  int local_9c;
  int local_84;
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  int local_8;
  
  if (*DAT_00a16714 < 0xd3) {
    *(undefined8 *)(param_1 + 0x170) = _DAT_00802e18;
  }
  else {
    *(undefined8 *)(param_1 + 0x170) = _DAT_007d07d0;
  }
  if (*(int *)(param_1 + 0x6c) != -1) {
    if (DAT_00a18a34 == -1) {
      if (*(char *)(param_1 + 0x11d) == '\0') {
        if (*(int *)(param_1 + 0x5c) != 0) {
          FUN_004fe844(*(undefined4 *)(param_1 + 0x5c));
          uVar1 = FUN_004fe844();
          FUN_0055cf80(uVar1);
        }
        if (*(int *)(param_1 + 0x6c) == 0) {
          FUN_0055f370(*(undefined4 *)(param_1 + 0x5c));
        }
      }
      else {
        uVar7 = 0x7f;
        uVar5 = 0;
        uVar1 = FUN_004fe844(0,0x7f);
        uVar1 = FUN_004bb950(uVar1,uVar5,uVar7);
        FUN_00401000(uVar1);
        FUN_00401510(uVar1);
        if (*(int *)(param_1 + 0x6c) == 0) {
          uVar1 = 0;
          FUN_00401000(0);
          FUN_00401470(uVar1);
        }
      }
    }
    else {
      if (*(char *)(param_1 + 0x11d) == '\0') {
        if (*(int *)(param_1 + 0x5c) == *(int *)(param_1 + 0x60)) {
          *(undefined4 *)(param_1 + 0x5c) = 0;
        }
        if (*(int *)(param_1 + 0x5c) != 0) {
          FUN_004fe844(*(undefined4 *)(param_1 + 0x5c));
          uVar1 = FUN_004fe844();
          FUN_0055cf80(uVar1);
        }
      }
      else if (*(char *)(param_1 + 0x11c) == '\0') {
        uVar7 = 0x7f;
        uVar5 = 0;
        uVar1 = FUN_004fe844(0,0x7f);
        uVar1 = FUN_004bb950(uVar1,uVar5,uVar7);
        FUN_00401000(uVar1);
        FUN_00401510(uVar1);
        if (*(int *)(param_1 + 0x6c) == 0) {
          uVar1 = 0;
          FUN_00401000(0);
          FUN_00401470(uVar1);
        }
      }
      if (*(char *)(param_1 + 0x11c) == '\0') {
        if (*(int *)(param_1 + 0x60) != 0) {
          FUN_004fe844(*(undefined4 *)(param_1 + 0x60));
          uVar1 = FUN_004fe844();
          FUN_0055cf80(uVar1);
        }
      }
      else if (((*(int *)(param_1 + 0x80) == 0) || (DAT_00a18b88 == 0)) &&
              (*(int *)(param_1 + 0x6c) == 0)) {
        if (DAT_00a1431c == '\0') {
          FUN_00401000();
          FUN_004014a0();
          DAT_00a1431c = '\x01';
        }
      }
      else {
        if ((DAT_00a1431c != '\0') && (*(int *)(param_1 + 0x80) != 0)) {
          DAT_00a1431c = '\0';
          FUN_00401000();
          FUN_004014c0();
        }
        uVar7 = 0x7f;
        uVar5 = 0;
        uVar1 = FUN_004fe844(0,0x7f);
        uVar1 = FUN_004bb950(uVar1,uVar5,uVar7);
        FUN_00401000(uVar1);
        FUN_00401510(uVar1);
      }
    }
    if ((*(int *)(param_1 + 0x5c) != 0) && (*(int *)(param_1 + 0x6c) == 0)) {
      FUN_0047c5e0(0,*(undefined4 *)(param_1 + 0x5c));
      *(undefined4 *)(param_1 + 0x5c) = 0;
    }
    if (*(int *)(param_1 + 0x6c) < 1) {
      *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
    }
    else {
      if (*(int *)(param_1 + 0x6c) - DAT_0084b244 < 1) {
        local_84 = 0;
      }
      else {
        local_84 = *(int *)(param_1 + 0x6c) - DAT_0084b244;
      }
      *(int *)(param_1 + 0x6c) = local_84;
    }
  }
  if (*(int *)(param_1 + 0x70) != -1) {
    if (*(int *)(param_1 + 100) == *(int *)(param_1 + 0x68)) {
      *(undefined4 *)(param_1 + 100) = 0;
    }
    if (*(int *)(param_1 + 100) != 0) {
      FUN_004fe844(*(undefined4 *)(param_1 + 100));
      uVar1 = FUN_004fe844();
      FUN_0055cf80(uVar1);
    }
    if (*(int *)(param_1 + 0x68) != 0) {
      FUN_004fe844(*(undefined4 *)(param_1 + 0x68));
      uVar1 = FUN_004fe844();
      FUN_0055cf80(uVar1);
    }
    if (*(int *)(param_1 + 0x70) == 0) {
      FUN_0047c5e0(1,*(undefined4 *)(param_1 + 100));
      *(undefined4 *)(param_1 + 100) = 0;
    }
    if ((*(int *)(param_1 + 100) != 0) && (*(int *)(param_1 + 0x70) == 0)) {
      FUN_0047c5e0(1,*(undefined4 *)(param_1 + 100));
      *(undefined4 *)(param_1 + 100) = 0;
    }
    if (*(int *)(param_1 + 0x70) < 1) {
      *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
    }
    else {
      if (*(int *)(param_1 + 0x70) - DAT_0084b244 < 1) {
        local_9c = 0;
      }
      else {
        local_9c = *(int *)(param_1 + 0x70) - DAT_0084b244;
      }
      *(int *)(param_1 + 0x70) = local_9c;
    }
  }
  local_8 = 0;
  do {
    iVar2 = FUN_004ce080();
    if (iVar2 <= local_8) {
      return;
    }
    puVar3 = (undefined4 *)FUN_004ce990(local_8);
    iVar2 = FUN_00560f10(*puVar3);
    if (iVar2 < 1) {
      puVar3 = (undefined4 *)FUN_004ce990(local_8);
      FUN_0055f370(*puVar3);
    }
    piVar4 = (int *)FUN_004ce990(local_8);
    if (*piVar4 == 0) {
      piVar4 = (int *)FUN_004ce990(local_8);
      if (*piVar4 == -1) {
        FUN_0047ce50();
        return;
      }
      uVar5 = 1;
      uVar1 = 1;
      puVar3 = (undefined4 *)FUN_004ce990(local_8);
      FUN_00561a00(*puVar3,uVar1,uVar5);
      piVar4 = (int *)FUN_004ce990(local_8);
      if (*piVar4 < 1) {
        puVar6 = local_10;
        iVar2 = local_8;
        FUN_004ce060(local_c);
        puVar3 = (undefined4 *)iterator__operator_(puVar6,iVar2);
        FUN_004ce2a0(local_14,*puVar3);
        puVar6 = local_1c;
        iVar2 = local_8;
        FUN_004ce060(local_18);
        puVar3 = (undefined4 *)iterator__operator_(puVar6,iVar2);
        FUN_004ce2a0(local_20,*puVar3);
        puVar6 = local_28;
        iVar2 = local_8;
        FUN_004ce060(local_24);
        puVar3 = (undefined4 *)iterator__operator_(puVar6,iVar2);
        FUN_004ce2a0(local_2c,*puVar3);
        local_8 = local_8 + -1;
      }
    }
    else {
      piVar4 = (int *)FUN_004ce990(local_8);
      if (*piVar4 < 0) {
        puVar3 = (undefined4 *)FUN_004ce990(local_8);
        iVar2 = FUN_00560f10(*puVar3);
        if (iVar2 < 1) {
          puVar3 = (undefined4 *)FUN_004ce990(local_8);
          FUN_0047c5e0(2,*puVar3);
          puVar6 = local_34;
          iVar2 = local_8;
          FUN_004ce060(local_30);
          puVar3 = (undefined4 *)iterator__operator_(puVar6,iVar2);
          FUN_004ce2a0(local_38,*puVar3);
          puVar6 = local_40;
          iVar2 = local_8;
          FUN_004ce060(local_3c);
          puVar3 = (undefined4 *)iterator__operator_(puVar6,iVar2);
          FUN_004ce2a0(local_44,*puVar3);
          puVar6 = local_4c;
          iVar2 = local_8;
          FUN_004ce060(local_48);
          puVar3 = (undefined4 *)iterator__operator_(puVar6,iVar2);
          FUN_004ce2a0(local_50,*puVar3);
          local_8 = local_8 + -1;
        }
      }
    }
    if (-1 < local_8) {
      piVar4 = (int *)FUN_004ce990(local_8);
      if (*piVar4 < 1) {
        puVar3 = (undefined4 *)FUN_004ce990(local_8);
        *puVar3 = 0xffffffff;
      }
      else {
        piVar4 = (int *)FUN_004ce990(local_8);
        if (*piVar4 - DAT_0084b244 < 1) {
          local_a4 = 0;
        }
        else {
          piVar4 = (int *)FUN_004ce990(local_8);
          local_a4 = *piVar4 - DAT_0084b244;
        }
        piVar4 = (int *)FUN_004ce990(local_8);
        *piVar4 = local_a4;
      }
    }
    local_8 = local_8 + 1;
  } while( true );
}

