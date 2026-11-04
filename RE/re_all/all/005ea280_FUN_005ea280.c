
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_005ea280(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  undefined1 uVar6;
  int *in_EAX;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  iVar2 = *in_EAX;
  iVar3 = in_EAX[1];
  iVar4 = in_EAX[2];
  if (*(char *)((int)in_EAX + 0x5d) == '\0') {
    fVar1 = *(float *)(iVar4 + 0x10);
    fVar5 = (float)_DAT_007d5348;
    if ((!NAN(fVar1) && !NAN(fVar5)) && fVar1 < fVar5 != (fVar1 == fVar5)) {
      return 0;
    }
    local_44 = *(float *)(iVar4 + 4);
    local_40 = *(float *)(iVar4 + 8);
    local_3c = *(float *)(iVar4 + 0xc);
    local_38 = *(float *)(iVar4 + 0x10);
    local_24 = *(float *)(iVar4 + 0x24);
    local_20 = *(float *)(iVar4 + 0x28);
    local_1c = *(float *)(iVar4 + 0x2c);
    local_18 = *(float *)(iVar4 + 0x30);
    local_34 = *(float *)(iVar4 + 0x14);
    local_30 = *(float *)(iVar4 + 0x18);
    local_2c = *(float *)(iVar4 + 0x1c);
    local_28 = *(float *)(iVar4 + 0x20);
    local_14 = *(float *)(iVar4 + 0x34);
    local_10 = *(float *)(iVar4 + 0x38);
    local_c = *(float *)(iVar4 + 0x3c);
    local_8 = *(float *)(iVar4 + 0x40);
  }
  else {
    fVar1 = (float)in_EAX[0x1b] * *(float *)(iVar4 + 0x10);
    fVar5 = (float)_DAT_007d5348;
    if ((!NAN(fVar1) && !NAN(fVar5)) && fVar1 < fVar5 != (fVar1 == fVar5)) {
      return 0;
    }
    local_44 = (float)in_EAX[0x18] * *(float *)(iVar4 + 4);
    local_40 = (float)in_EAX[0x19] * *(float *)(iVar4 + 8);
    local_3c = (float)in_EAX[0x1a] * *(float *)(iVar4 + 0xc);
    local_38 = (float)in_EAX[0x1b] * *(float *)(iVar4 + 0x10);
    local_24 = (float)in_EAX[0x20] * *(float *)(iVar4 + 0x24);
    local_20 = (float)in_EAX[0x21] * *(float *)(iVar4 + 0x28);
    local_1c = (float)in_EAX[0x22] * *(float *)(iVar4 + 0x2c);
    local_18 = (float)in_EAX[0x23] * *(float *)(iVar4 + 0x30);
    local_14 = (float)in_EAX[0x24] * *(float *)(iVar4 + 0x34);
    local_10 = (float)in_EAX[0x25] * *(float *)(iVar4 + 0x38);
    local_c = (float)in_EAX[0x26] * *(float *)(iVar4 + 0x3c);
    local_8 = (float)in_EAX[0x27] * *(float *)(iVar4 + 0x40);
    local_34 = (float)in_EAX[0x1c] * *(float *)(iVar4 + 0x14);
    local_30 = (float)in_EAX[0x1d] * *(float *)(iVar4 + 0x18);
    local_2c = (float)in_EAX[0x1e] * *(float *)(iVar4 + 0x1c);
    local_28 = (float)in_EAX[0x1f] * *(float *)(iVar4 + 0x20);
  }
  local_4 = *(undefined4 *)(iVar4 + 0x44);
  FUN_0056d420(&DAT_00a38e2c,iVar4 + 0x48,0x10);
  DAT_00a38de4 = 1;
  DAT_00ef72cc = 1;
  FUN_005b9a40(&local_44);
  if (DAT_00a3810c == 0) {
    uVar6 = *(undefined1 *)(iVar3 + 0x49);
  }
  else {
    uVar6 = 0;
  }
  FUN_005b9d00(uVar6);
  iVar7 = in_EAX[0x2d];
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_4c = 0x3f800000;
  if (iVar7 == -1) {
    iVar7 = *(int *)(iVar4 + 0x1a0);
  }
  local_48 = ((float)in_EAX[0x28] * (float)iVar7) / (float)_DAT_0081ec30;
  FUN_005bb3f0(&local_54);
  if (DAT_00a3810c == 0) {
    uVar9 = in_EAX[0x2c];
    if (uVar9 == 0xffffffff) {
      uVar9 = *(uint *)(iVar4 + 0x19c);
    }
    if (0xe < uVar9) goto switchD_005ea4b8_caseD_4;
  }
  else {
    uVar9 = 0;
  }
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch((&DAT_005ea568)[uVar9]) {
  case 0:
    break;
  case 1:
    if (*(char *)(*(int *)(iVar2 + 8) + 0x24e) == '\0') {
      uVar9 = 1;
    }
    else {
      uVar9 = 0x11;
    }
    break;
  case 2:
    if (*(char *)(*(int *)(iVar2 + 8) + 0x24e) == '\0') {
      uVar9 = 2;
    }
    else {
      uVar9 = 0x12;
    }
    break;
  case 3:
    uVar9 = 0x10;
    break;
  case 4:
    goto switchD_005ea4b8_caseD_4;
  }
  FUN_005bb510(uVar9);
switchD_005ea4b8_caseD_4:
  if ((((*(int *)(iVar3 + 0x1c) != 0) || (_DAT_007d56d8 < local_24)) || (_DAT_007d56d8 < local_20))
     || (_DAT_007d56d8 < local_1c)) {
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  FUN_005b9b80(uVar8);
  FUN_005b9c00(*(undefined4 *)(iVar3 + 0x18));
  FUN_005b9c80(*(undefined4 *)(iVar3 + 0x1c));
  return 1;
}

