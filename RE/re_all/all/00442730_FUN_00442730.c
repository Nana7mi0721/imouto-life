
undefined4 __thiscall FUN_00442730(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_1c;
  int local_10;
  int local_c;
  
  bVar1 = false;
  do {
    if ((param_4 < 1) || (param_4 % 3 != 0)) {
      if ((param_4 + 2) % 3 == 0) {
        local_28 = -*(int *)(param_1 + 0xb4);
      }
      else {
        local_28 = 0;
      }
      local_24 = local_28;
    }
    else {
      local_24 = *(int *)(param_1 + 0xb4);
    }
    local_10 = param_2 + local_24;
    if ((param_4 < 1) || ((int)(param_4 + (param_4 >> 0x1f & 3U)) >> 2 != 0)) {
      if (param_4 / 7 == 1) {
        local_30 = -*(int *)(param_1 + 0xb4);
      }
      else {
        local_30 = 0;
      }
      local_2c = local_30;
    }
    else {
      local_2c = *(int *)(param_1 + 0xb4);
    }
    local_c = param_3 + local_2c;
    if ((*(int *)(param_1 + 0xb4) == 1) && (*(char *)(param_1 + 0xb9) != '\0')) {
      local_34 = 1;
    }
    else {
      local_34 = 0;
    }
    cVar3 = FUN_0047eb30(local_10,local_c + local_34);
    if (cVar3 == '\0') {
      return 0;
    }
    if (DAT_00a180f4 != '\0') {
      iVar4 = FUN_0047a490();
      iVar5 = FUN_0047a490();
      local_10 = (local_10 + iVar4 * 2) % (iVar5 << 1);
    }
    if (DAT_00a180f5 != '\0') {
      iVar4 = FUN_0047a4b0();
      iVar5 = FUN_0047a4b0();
      local_c = (local_c + iVar4 * 2) % (iVar5 << 1);
    }
    if (*(char *)(param_1 + 0x53) != '\0') {
      return 1;
    }
    cVar3 = FUN_0044a350(param_2,param_3,param_4,0xffffffff,*(undefined4 *)(param_1 + 0xb4));
    if (cVar3 == '\0') {
      return 0;
    }
    cVar3 = FUN_0044a350(local_10,local_c,10 - param_4,0xffffffff,*(undefined4 *)(param_1 + 0xb4));
    if (cVar3 == '\0') {
      FUN_0044a350(local_10,local_c,10 - param_4,0xffffffff,*(undefined4 *)(param_1 + 0xb4));
      return 0;
    }
    for (local_1c = 0; iVar4 = FUN_004d29a0(), local_1c < iVar4; local_1c = local_1c + 1) {
      iVar4 = FUN_004d2a00(local_1c);
      bVar2 = false;
      if (*(char *)(iVar4 + 0xb9) == '\0') {
LAB_00442a13:
        iVar6 = FUN_0047a4b0();
        iVar5 = *(int *)(iVar4 + 0x2c);
        iVar7 = FUN_0047a4b0();
        iVar8 = FUN_0047a4b0();
        if ((iVar5 + iVar6 * 2) % (iVar7 << 1) == local_c % (iVar8 << 1)) {
          bVar2 = true;
        }
      }
      else {
        iVar6 = FUN_0047a4b0();
        iVar5 = *(int *)(iVar4 + 0x2c);
        iVar7 = FUN_0047a4b0();
        if ((iVar5 + iVar6 * 2) % (iVar7 << 1) != local_c) {
          iVar6 = FUN_0047a4b0();
          iVar5 = *(int *)(iVar4 + 0x2c);
          iVar7 = FUN_0047a4b0();
          iVar8 = FUN_0047a4b0();
          if ((iVar5 + iVar6 * 2) % (iVar7 << 1) != (local_c + 1) % (iVar8 << 1)) goto LAB_00442a13;
        }
        bVar2 = true;
      }
      if (*(int *)(iVar4 + 0x24) != *(int *)(param_1 + 0x24)) {
        iVar6 = FUN_0047a490();
        iVar5 = *(int *)(iVar4 + 0x28);
        iVar7 = FUN_0047a490();
        iVar8 = FUN_0047a490();
        iVar9 = FUN_0047a490();
        if ((iVar5 + iVar6 * 2) % (iVar7 << 1) != (local_10 + -1 + iVar8 * 2) % (iVar9 << 1)) {
          iVar6 = FUN_0047a490();
          iVar5 = *(int *)(iVar4 + 0x28);
          iVar7 = FUN_0047a490();
          if ((iVar5 + iVar6 * 2) % (iVar7 << 1) != local_10) {
            iVar6 = FUN_0047a490();
            iVar5 = *(int *)(iVar4 + 0x28);
            iVar7 = FUN_0047a490();
            iVar8 = FUN_0047a490();
            if ((iVar5 + iVar6 * 2) % (iVar7 << 1) != (local_10 + 1) % (iVar8 << 1))
            goto LAB_0044295e;
          }
        }
        if ((bVar2) && (*(char *)(iVar4 + 0x53) == '\0')) {
          if ((*(char *)(param_1 + 0x54) == '\0') && (*(char *)(param_1 + 0xbf) == '\0')) {
            return 0;
          }
          cVar3 = operator!=<>(iVar4 + 8,&DAT_007ce959);
          if ((cVar3 != '\0') || (*(int *)(iVar4 + 0x40) != -1)) {
            return 0;
          }
        }
      }
LAB_0044295e:
    }
    bVar2 = false;
    if (DAT_00a144f1 == '\0') {
LAB_00442bf8:
      iVar4 = FUN_0047a4b0();
      iVar4 = DAT_00a14464 + iVar4 * 2;
      iVar5 = FUN_0047a4b0();
      if (iVar4 % (iVar5 << 1) == local_c) {
        bVar2 = true;
      }
    }
    else {
      iVar4 = FUN_0047a4b0();
      iVar4 = DAT_00a14464 + iVar4 * 2;
      iVar5 = FUN_0047a4b0();
      if (iVar4 % (iVar5 << 1) != local_c) {
        iVar5 = FUN_0047a4b0();
        iVar4 = DAT_00a14464 + -1;
        iVar6 = FUN_0047a4b0();
        if ((iVar4 + iVar5 * 2) % (iVar6 << 1) != local_c) goto LAB_00442bf8;
      }
      bVar2 = true;
    }
    if (*(char *)(param_1 + 0x54) == '\0') {
      iVar5 = FUN_0047a490();
      iVar4 = FUN_0047a490();
      iVar4 = DAT_00a14460 + iVar4 * 2;
      iVar6 = FUN_0047a490();
      if ((local_10 + 1) % (iVar5 << 1) != iVar4 % (iVar6 << 1)) {
        iVar5 = FUN_0047a490();
        iVar4 = FUN_0047a490();
        iVar4 = DAT_00a14460 + iVar4 * 2;
        iVar6 = FUN_0047a490();
        if (local_10 % (iVar5 << 1) != iVar4 % (iVar6 << 1)) {
          iVar4 = FUN_0047a490();
          iVar4 = DAT_00a14460 + iVar4 * 2;
          iVar5 = FUN_0047a490();
          iVar6 = FUN_0047a490();
          iVar7 = FUN_0047a490();
          if (iVar4 % (iVar5 << 1) != (local_10 + -1 + iVar6 * 2) % (iVar7 << 1)) goto LAB_00442d4a;
        }
      }
      if (((bVar2) && (DAT_00a1448b == '\0')) &&
         ((cVar3 = operator!=<>(param_1 + 8,&DAT_007ce95a), cVar3 != '\0' ||
          (*(int *)(param_1 + 0x40) != -1)))) {
        return 0;
      }
    }
LAB_00442d4a:
    if (((bVar1) || (*(int *)(param_1 + 0xb4) != 1)) || (*(char *)(param_1 + 0xb9) == '\0')) {
      return 1;
    }
    param_3 = param_3 + -1;
    bVar1 = true;
  } while( true );
}

