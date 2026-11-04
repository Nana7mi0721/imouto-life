
undefined4 FUN_00542e50(int param_1,uint param_2,byte *param_3,undefined1 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  byte *local_18;
  byte *local_14;
  int local_10;
  
  iVar1 = *(int *)((int)param_4 + 0x430);
  local_14 = (byte *)(param_2 * (int)param_3 + param_1);
  iVar2 = (int)(param_2 + ((int)param_2 >> 0x1f & 3U)) >> 2;
  if (0 < (int)param_3) {
    param_4 = (undefined1 *)(*(int *)((int)param_4 + 0x434) + 2);
    local_18 = (byte *)(param_1 + 2);
    local_10 = (int)param_3;
    do {
      if (0 < iVar2) {
        pbVar7 = local_18;
        puVar8 = param_4;
        param_1 = iVar2;
        param_3 = local_14;
        do {
          iVar3 = (*param_3 - 0x80) * 0xe2d0;
          iVar5 = (param_3[1] - 0x80) * 0xb374;
          iVar4 = (*param_3 - 0x80) * -0x2c08 + (param_3[1] - 0x80) * -0x5b64;
          iVar9 = (uint)pbVar7[-2] * 0x8000;
          iVar10 = iVar9 + iVar3;
          if (iVar10 < 0) {
            uVar6 = 0;
          }
          else if (iVar10 < 0x7f8001) {
            uVar6 = (undefined1)(iVar10 >> 0xf);
          }
          else {
            uVar6 = 0xff;
          }
          puVar8[-2] = uVar6;
          iVar10 = iVar9 + iVar4;
          if (iVar10 < 0) {
            uVar6 = 0;
          }
          else if (iVar10 < 0x7f8001) {
            uVar6 = (undefined1)(iVar10 >> 0xf);
          }
          else {
            uVar6 = 0xff;
          }
          iVar9 = iVar9 + iVar5;
          puVar8[-1] = uVar6;
          if (iVar9 < 0) {
            uVar6 = 0;
          }
          else if (iVar9 < 0x7f8001) {
            uVar6 = (undefined1)(iVar9 >> 0xf);
          }
          else {
            uVar6 = 0xff;
          }
          *puVar8 = uVar6;
          puVar8[1] = 0xff;
          iVar9 = (uint)pbVar7[-1] * 0x8000;
          iVar10 = iVar9 + iVar3;
          if (iVar10 < 0) {
            uVar6 = 0;
          }
          else if (iVar10 < 0x7f8001) {
            uVar6 = (undefined1)(iVar10 >> 0xf);
          }
          else {
            uVar6 = 0xff;
          }
          puVar8[2] = uVar6;
          iVar10 = iVar9 + iVar4;
          if (iVar10 < 0) {
            uVar6 = 0;
          }
          else if (iVar10 < 0x7f8001) {
            uVar6 = (undefined1)(iVar10 >> 0xf);
          }
          else {
            uVar6 = 0xff;
          }
          iVar9 = iVar9 + iVar5;
          puVar8[3] = uVar6;
          if (iVar9 < 0) {
            uVar6 = 0;
          }
          else if (iVar9 < 0x7f8001) {
            uVar6 = (undefined1)(iVar9 >> 0xf);
          }
          else {
            uVar6 = 0xff;
          }
          puVar8[4] = uVar6;
          puVar8[5] = 0xff;
          iVar9 = (uint)*pbVar7 * 0x8000;
          iVar10 = iVar9 + iVar3;
          if (iVar10 < 0) {
            uVar6 = 0;
          }
          else if (iVar10 < 0x7f8001) {
            uVar6 = (undefined1)(iVar10 >> 0xf);
          }
          else {
            uVar6 = 0xff;
          }
          puVar8[6] = uVar6;
          iVar10 = iVar9 + iVar4;
          if (iVar10 < 0) {
            uVar6 = 0;
          }
          else if (iVar10 < 0x7f8001) {
            uVar6 = (undefined1)(iVar10 >> 0xf);
          }
          else {
            uVar6 = 0xff;
          }
          iVar9 = iVar9 + iVar5;
          puVar8[7] = uVar6;
          if (iVar9 < 0) {
            uVar6 = 0;
          }
          else if (iVar9 < 0x7f8001) {
            uVar6 = (undefined1)(iVar9 >> 0xf);
          }
          else {
            uVar6 = 0xff;
          }
          puVar8[8] = uVar6;
          puVar8[9] = 0xff;
          iVar10 = (uint)pbVar7[1] * 0x8000;
          iVar3 = iVar10 + iVar3;
          if (iVar3 < 0) {
            uVar6 = 0;
          }
          else if (iVar3 < 0x7f8001) {
            uVar6 = (undefined1)(iVar3 >> 0xf);
          }
          else {
            uVar6 = 0xff;
          }
          iVar4 = iVar4 + iVar10;
          puVar8[10] = uVar6;
          if (iVar4 < 0) {
            uVar6 = 0;
          }
          else if (iVar4 < 0x7f8001) {
            uVar6 = (undefined1)(iVar4 >> 0xf);
          }
          else {
            uVar6 = 0xff;
          }
          puVar8[0xb] = uVar6;
          iVar10 = iVar10 + iVar5;
          if (iVar10 < 0) {
            uVar6 = 0;
          }
          else if (iVar10 < 0x7f8001) {
            uVar6 = (undefined1)(iVar10 >> 0xf);
          }
          else {
            uVar6 = 0xff;
          }
          param_3 = param_3 + 2;
          puVar8[0xc] = uVar6;
          puVar8[0xd] = 0xff;
          pbVar7 = pbVar7 + 4;
          puVar8 = puVar8 + 0x10;
          param_1 = param_1 + -1;
        } while (param_1 != 0);
      }
      param_4 = param_4 + iVar1;
      local_18 = local_18 + param_2;
      local_14 = local_14 + (param_2 >> 1);
      local_10 = local_10 + -1;
    } while (local_10 != 0);
  }
  return 0;
}

