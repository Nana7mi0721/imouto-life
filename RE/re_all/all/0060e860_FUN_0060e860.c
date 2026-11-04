
undefined4 * __thiscall FUN_0060e860(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_c [3];
  
  *param_1 = &PTR_FUN_008040cc;
  iVar1 = FUN_00646b30(0x164,0x10);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    FUN_005f5190(iVar1 + 0x54,0x10,5,FUN_0061ddb0);
    FUN_005f5190(iVar1 + 0xa4,0x10,5,FUN_0061ddb0);
    FUN_0060f140();
  }
  param_1[8] = iVar1;
  if (param_2[7] == 0) {
    puVar2 = (undefined4 *)FUN_00646b30(4,0x10);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_LAB_008040bc;
      goto LAB_0060e8f6;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_00646b30(4,0x10);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_LAB_008040c4;
      goto LAB_0060e8f6;
    }
  }
  puVar2 = (undefined4 *)0x0;
LAB_0060e8f6:
  param_1[9] = puVar2;
  iVar1 = FUN_00646b30(0x18,0x10);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00618880(param_1[8],param_1[9]);
  }
  param_1[10] = uVar3;
  puVar2 = (undefined4 *)FUN_00646b30(8,0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = &PTR_LAB_008040b4;
  }
  param_1[0xb] = puVar2;
  puVar2 = (undefined4 *)FUN_00646b30(8,0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = &PTR_LAB_008040ac;
  }
  param_1[0xc] = puVar2;
  puVar2 = (undefined4 *)FUN_00646b30(8,0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = &PTR_LAB_008040a4;
  }
  param_1[0xd] = puVar2;
  puVar2 = (undefined4 *)FUN_00646b30(8,0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = &PTR_LAB_0080409c;
  }
  param_1[0xe] = puVar2;
  puVar2 = (undefined4 *)FUN_00646b30(8,0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = &PTR_LAB_00804094;
  }
  param_1[0xf] = puVar2;
  puVar2 = (undefined4 *)FUN_00646b30(8,0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = &PTR_LAB_0080408c;
  }
  param_1[0x10] = puVar2;
  puVar2 = (undefined4 *)FUN_00646b30(8,0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = &PTR_LAB_00804084;
  }
  param_1[0x12] = puVar2;
  puVar2 = (undefined4 *)FUN_00646b30(8,0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = &PTR_LAB_00804084;
  }
  param_1[0x13] = puVar2;
  *(undefined1 *)(puVar2 + 1) = 1;
  puVar2 = (undefined4 *)FUN_00646b30(8,0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = &PTR_LAB_0080407c;
  }
  param_1[0x11] = puVar2;
  puVar2 = (undefined4 *)FUN_00646b30(0x10,0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar2 + 1) = 0;
    puVar2[2] = 1;
    puVar2[3] = 1;
    *puVar2 = &PTR_LAB_00804074;
  }
  param_1[0x15] = puVar2;
  puVar2 = (undefined4 *)FUN_00646b30(0x10,0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar2 + 1) = 0;
    puVar2[2] = 1;
    puVar2[3] = 1;
    *puVar2 = &PTR_LAB_00804074;
  }
  param_1[0x14] = puVar2;
  *(undefined1 *)(puVar2 + 1) = 1;
  piVar4 = param_2 + 5;
  local_c[0] = 0x80;
  local_c[1] = 0x50;
  local_c[2] = 0x2c;
  if (param_2[5] < 0x80) {
    piVar4 = local_c;
  }
  local_c[0] = *piVar4;
  piVar5 = local_c;
  if (*piVar4 < 0x51) {
    piVar5 = local_c + 1;
  }
  local_c[0] = *piVar5;
  piVar4 = local_c;
  if (*piVar5 < 0x2d) {
    piVar4 = local_c + 2;
  }
  iVar1 = *piVar4;
  local_c[0] = iVar1;
  if (*param_2 == 0) {
    *(undefined1 *)(param_1 + 3) = 1;
    puVar2 = (undefined4 *)FUN_00646b30(0x14,0x10);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      iVar1 = param_2[6];
      puVar2[1] = 0;
      puVar2[3] = 0;
      *(undefined1 *)(puVar2 + 4) = 0;
      *puVar2 = 0;
      puVar2[2] = 0;
      uVar3 = FUN_00646b30(iVar1,0x10);
      puVar2[1] = iVar1;
      *puVar2 = uVar3;
      iVar1 = local_c[0];
    }
    param_1[2] = puVar2;
  }
  else {
    *(undefined1 *)(param_1 + 3) = 0;
    param_1[2] = *param_2;
  }
  if (param_2[1] == 0) {
    *(undefined1 *)(param_1 + 5) = 1;
    piVar4 = (int *)FUN_00646b30(0x14,0x10);
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      iVar7 = param_2[3];
      *piVar4 = 0x2ac;
      piVar4[1] = iVar7;
      piVar5 = (int *)FUN_00646b30(iVar7 * 0x2ac,0x10);
      piVar4[4] = (int)piVar5;
      piVar4[3] = (int)piVar5;
      iVar7 = piVar4[1] + -1;
      piVar4[2] = piVar4[1];
      if (iVar7 != 0) {
        iVar6 = *piVar4;
        do {
          *piVar5 = iVar6 + (int)piVar5;
          iVar6 = *piVar4;
          piVar5 = (int *)((int)piVar5 + iVar6);
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      *piVar5 = 0;
    }
    param_1[4] = piVar4;
  }
  else {
    *(undefined1 *)(param_1 + 5) = 0;
    param_1[4] = param_2[1];
  }
  if (param_2[2] != 0) {
    *(undefined1 *)(param_1 + 7) = 0;
    param_1[6] = param_2[2];
    return param_1;
  }
  *(undefined1 *)(param_1 + 7) = 1;
  piVar4 = (int *)FUN_00646b30(0x14,0x10);
  if (piVar4 == (int *)0x0) {
    param_1[6] = 0;
    return param_1;
  }
  iVar7 = param_2[4];
  *piVar4 = iVar1;
  piVar4[1] = iVar7;
  piVar5 = (int *)FUN_00646b30(iVar7 * iVar1,0x10);
  piVar4[4] = (int)piVar5;
  piVar4[3] = (int)piVar5;
  iVar1 = piVar4[1] + -1;
  piVar4[2] = piVar4[1];
  if (iVar1 != 0) {
    iVar7 = *piVar4;
    do {
      *piVar5 = iVar7 + (int)piVar5;
      iVar7 = *piVar4;
      piVar5 = (int *)((int)piVar5 + iVar7);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  *piVar5 = 0;
  param_1[6] = piVar4;
  return param_1;
}

