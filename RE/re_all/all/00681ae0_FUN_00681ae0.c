
uint FUN_00681ae0(int *param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  int iVar11;
  uint *puVar12;
  
  puVar4 = (undefined4 *)param_1[6];
  iVar11 = puVar4[1];
  puVar8 = (undefined1 *)*puVar4;
  *(undefined1 *)(param_1 + 0x32) = param_2;
  *(undefined1 *)((int)param_1 + 0xc9) = param_3;
  *(undefined1 *)((int)param_1 + 0xca) = param_4;
  if (iVar11 == 0) {
    uVar6 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar6 == '\0') goto LAB_00681e3f;
    puVar8 = (undefined1 *)*puVar4;
    iVar11 = puVar4[1];
  }
  iVar11 = iVar11 + -1;
  uVar1 = *puVar8;
  puVar8 = puVar8 + 1;
  if (iVar11 == 0) {
    uVar6 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar6 == '\0') goto LAB_00681e3f;
    puVar8 = (undefined1 *)*puVar4;
    iVar11 = puVar4[1];
  }
  uVar2 = *puVar8;
  iVar11 = iVar11 + -1;
  pbVar9 = puVar8 + 1;
  if (iVar11 == 0) {
    uVar6 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar6 == '\0') goto LAB_00681e3f;
    pbVar9 = (byte *)*puVar4;
    iVar11 = puVar4[1];
  }
  iVar11 = iVar11 + -1;
  pbVar10 = pbVar9 + 1;
  param_1[0x30] = (uint)*pbVar9;
  if (iVar11 == 0) {
    uVar6 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar6 == '\0') goto LAB_00681e3f;
    pbVar10 = (byte *)*puVar4;
    iVar11 = puVar4[1];
  }
  iVar11 = iVar11 + -1;
  pbVar9 = pbVar10 + 1;
  param_1[8] = (uint)*pbVar10 << 8;
  if (iVar11 == 0) {
    uVar6 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar6 == '\0') goto LAB_00681e3f;
    pbVar9 = (byte *)*puVar4;
    iVar11 = puVar4[1];
  }
  iVar11 = iVar11 + -1;
  pbVar10 = pbVar9 + 1;
  param_1[8] = param_1[8] + (uint)*pbVar9;
  if (iVar11 == 0) {
    uVar6 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar6 == '\0') goto LAB_00681e3f;
    pbVar10 = (byte *)*puVar4;
    iVar11 = puVar4[1];
  }
  iVar11 = iVar11 + -1;
  pbVar9 = pbVar10 + 1;
  param_1[7] = (uint)*pbVar10 << 8;
  if (iVar11 == 0) {
    uVar6 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar6 == '\0') goto LAB_00681e3f;
    pbVar9 = (byte *)*puVar4;
    iVar11 = puVar4[1];
  }
  iVar11 = iVar11 + -1;
  pbVar10 = pbVar9 + 1;
  param_1[7] = param_1[7] + (uint)*pbVar9;
  if (iVar11 == 0) {
    uVar6 = (*(code *)puVar4[3])(param_1);
    if ((char)uVar6 == '\0') {
LAB_00681e3f:
      return uVar6 & 0xffffff00;
    }
    pbVar10 = (byte *)*puVar4;
    iVar11 = puVar4[1];
  }
  iVar7 = *param_1;
  param_1[9] = (uint)*pbVar10;
  iVar11 = iVar11 + -1;
  *(int *)(iVar7 + 0x18) = param_1[0x65];
  *(int *)(iVar7 + 0x1c) = param_1[7];
  *(int *)(iVar7 + 0x20) = param_1[8];
  *(int *)(iVar7 + 0x24) = param_1[9];
  pbVar10 = pbVar10 + 1;
  *(undefined4 *)(*param_1 + 0x14) = 0x66;
  (**(code **)(*param_1 + 4))(param_1,1);
  if (*(char *)(param_1[0x6b] + 0xd) != '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x3d;
    (**(code **)*param_1)(param_1);
  }
  if (((param_1[8] == 0) || (param_1[7] == 0)) || (param_1[9] < 1)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x21;
    (**(code **)*param_1)(param_1);
  }
  if (CONCAT11(uVar1,uVar2) - 8 != param_1[9] * 3) {
    *(undefined4 *)(*param_1 + 0x14) = 0xc;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[0x31] == 0) {
    iVar7 = (**(code **)param_1[1])(param_1,1,param_1[9] * 0x58);
    param_1[0x31] = iVar7;
  }
  uVar6 = param_1[9];
  _param_2 = 0;
  if (0 < (int)uVar6) {
    do {
      if (iVar11 == 0) {
        uVar6 = (*(code *)puVar4[3])(param_1);
        if ((char)uVar6 == '\0') goto LAB_00681e3f;
        pbVar10 = (byte *)*puVar4;
        iVar11 = puVar4[1];
      }
      puVar5 = (uint *)param_1[0x31];
      iVar11 = iVar11 + -1;
      uVar6 = (uint)*pbVar10;
      pbVar10 = pbVar10 + 1;
      _param_3 = 0;
      puVar12 = puVar5;
      if (0 < (int)_param_2) {
LAB_00681d41:
        if (uVar6 != *puVar12) goto code_r0x00681d45;
        uVar6 = *puVar5;
        puVar12 = puVar5 + 0x16;
        if (1 < (int)_param_2) {
          _param_3 = _param_2 - 1;
          do {
            if ((int)uVar6 < (int)*puVar12) {
              uVar6 = *puVar12;
            }
            puVar12 = puVar12 + 0x16;
            _param_3 = _param_3 + -1;
          } while (_param_3 != 0);
        }
        uVar6 = uVar6 + 1;
      }
LAB_00681d87:
      *puVar12 = uVar6;
      puVar12[1] = _param_2;
      if (iVar11 == 0) {
        uVar6 = (*(code *)puVar4[3])(param_1);
        if ((char)uVar6 == '\0') goto LAB_00681e3f;
        pbVar10 = (byte *)*puVar4;
        iVar11 = puVar4[1];
      }
      iVar11 = iVar11 + -1;
      bVar3 = *pbVar10;
      pbVar10 = pbVar10 + 1;
      puVar12[3] = bVar3 & 0xf;
      puVar12[2] = (int)(uint)bVar3 >> 4;
      if (iVar11 == 0) {
        uVar6 = (*(code *)puVar4[3])(param_1);
        if ((char)uVar6 == '\0') goto LAB_00681e3f;
        pbVar10 = (byte *)*puVar4;
        iVar11 = puVar4[1];
      }
      iVar11 = iVar11 + -1;
      puVar12[4] = (uint)*pbVar10;
      iVar7 = *param_1;
      pbVar10 = pbVar10 + 1;
      *(uint *)(iVar7 + 0x18) = *puVar12;
      *(uint *)(iVar7 + 0x1c) = puVar12[2];
      *(uint *)(iVar7 + 0x20) = puVar12[3];
      *(uint *)(iVar7 + 0x24) = puVar12[4];
      *(undefined4 *)(*param_1 + 0x14) = 0x67;
      (**(code **)(*param_1 + 4))(param_1,1);
      uVar6 = _param_2 + 1;
      _param_2 = uVar6;
    } while ((int)uVar6 < param_1[9]);
  }
  *(undefined1 *)(param_1[0x6b] + 0xd) = 1;
  *puVar4 = pbVar10;
  puVar4[1] = iVar11;
  return CONCAT31((int3)(uVar6 >> 8),1);
code_r0x00681d45:
  puVar12 = puVar12 + 0x16;
  _param_3 = _param_3 + 1;
  if ((int)_param_2 <= _param_3) goto LAB_00681d87;
  goto LAB_00681d41;
}

