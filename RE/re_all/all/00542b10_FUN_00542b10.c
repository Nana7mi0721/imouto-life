
undefined4 FUN_00542b10(byte *param_1,uint param_2,int param_3,byte *param_4)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  int local_2c;
  byte *local_28;
  byte *local_24;
  byte *local_20;
  byte *local_1c;
  undefined1 *local_18;
  int local_14;
  
  iVar3 = param_2 * param_3;
  local_28 = param_1;
  local_24 = param_1 + iVar3;
  iVar1 = *(int *)((int)param_4 + 0x430);
  local_20 = local_24 + ((int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2);
  local_14 = param_3 / 2;
  if (0 < local_14) {
    local_18 = (undefined1 *)(*(int *)((int)param_4 + 0x434) + 2);
    do {
      param_4 = local_28;
      local_2c = 0;
      if (0 < (int)param_2 / 2) {
        local_1c = local_28 + param_2;
        puVar6 = local_18;
        do {
          iVar7 = (local_20[local_2c] - 0x80) * 0xe2d0;
          iVar5 = (local_24[local_2c] - 0x80) * 0xb374;
          iVar4 = (local_20[local_2c] - 0x80) * -0x2c08 + (local_24[local_2c] - 0x80) * -0x5b64;
          iVar8 = (uint)*param_4 * 0x8000;
          iVar3 = iVar8 + iVar7;
          if (iVar3 < 0) {
            uVar2 = 0;
          }
          else if (iVar3 < 0x7f8001) {
            uVar2 = (undefined1)(iVar3 >> 0xf);
          }
          else {
            uVar2 = 0xff;
          }
          puVar6[-2] = uVar2;
          iVar3 = iVar8 + iVar4;
          if (iVar3 < 0) {
            uVar2 = 0;
          }
          else if (iVar3 < 0x7f8001) {
            uVar2 = (undefined1)(iVar3 >> 0xf);
          }
          else {
            uVar2 = 0xff;
          }
          iVar8 = iVar8 + iVar5;
          puVar6[-1] = uVar2;
          if (iVar8 < 0) {
            uVar2 = 0;
          }
          else if (iVar8 < 0x7f8001) {
            uVar2 = (undefined1)(iVar8 >> 0xf);
          }
          else {
            uVar2 = 0xff;
          }
          *puVar6 = uVar2;
          puVar6[1] = 0xff;
          iVar8 = (uint)local_1c[1 - param_2] * 0x8000;
          iVar3 = iVar8 + iVar7;
          if (iVar3 < 0) {
            uVar2 = 0;
          }
          else if (iVar3 < 0x7f8001) {
            uVar2 = (undefined1)(iVar3 >> 0xf);
          }
          else {
            uVar2 = 0xff;
          }
          puVar6[2] = uVar2;
          iVar3 = iVar8 + iVar4;
          if (iVar3 < 0) {
            uVar2 = 0;
          }
          else if (iVar3 < 0x7f8001) {
            uVar2 = (undefined1)(iVar3 >> 0xf);
          }
          else {
            uVar2 = 0xff;
          }
          puVar6[3] = uVar2;
          iVar8 = iVar8 + iVar5;
          if (iVar8 < 0) {
            uVar2 = 0;
          }
          else if (iVar8 < 0x7f8001) {
            uVar2 = (undefined1)(iVar8 >> 0xf);
          }
          else {
            uVar2 = 0xff;
          }
          puVar6[4] = uVar2;
          puVar6[5] = 0xff;
          iVar8 = (uint)*local_1c * 0x8000;
          iVar3 = iVar8 + iVar7;
          if (iVar3 < 0) {
            uVar2 = 0;
          }
          else if (iVar3 < 0x7f8001) {
            uVar2 = (undefined1)(iVar3 >> 0xf);
          }
          else {
            uVar2 = 0xff;
          }
          puVar6[iVar1 + -2] = uVar2;
          iVar3 = iVar8 + iVar4;
          if (iVar3 < 0) {
            uVar2 = 0;
          }
          else if (iVar3 < 0x7f8001) {
            uVar2 = (undefined1)(iVar3 >> 0xf);
          }
          else {
            uVar2 = 0xff;
          }
          puVar6[iVar1 + -1] = uVar2;
          iVar8 = iVar8 + iVar5;
          if (iVar8 < 0) {
            uVar2 = 0;
          }
          else if (iVar8 < 0x7f8001) {
            uVar2 = (undefined1)(iVar8 >> 0xf);
          }
          else {
            uVar2 = 0xff;
          }
          puVar6[iVar1] = uVar2;
          puVar6[iVar1 + 1] = 0xff;
          iVar3 = (uint)local_1c[1] * 0x8000;
          iVar7 = iVar3 + iVar7;
          if (iVar7 < 0) {
            uVar2 = 0;
          }
          else if (iVar7 < 0x7f8001) {
            uVar2 = (undefined1)(iVar7 >> 0xf);
          }
          else {
            uVar2 = 0xff;
          }
          puVar6[iVar1 + 2] = uVar2;
          iVar4 = iVar4 + iVar3;
          if (iVar4 < 0) {
            uVar2 = 0;
          }
          else if (iVar4 < 0x7f8001) {
            uVar2 = (undefined1)(iVar4 >> 0xf);
          }
          else {
            uVar2 = 0xff;
          }
          puVar6[iVar1 + 3] = uVar2;
          iVar5 = iVar5 + iVar3;
          if (iVar5 < 0) {
            uVar2 = 0;
          }
          else if (iVar5 < 0x7f8001) {
            uVar2 = (undefined1)(iVar5 >> 0xf);
          }
          else {
            uVar2 = 0xff;
          }
          param_4 = param_4 + 2;
          puVar6[iVar1 + 4] = uVar2;
          local_2c = local_2c + 1;
          puVar6[iVar1 + 5] = 0xff;
          local_1c = local_1c + 2;
          puVar6 = puVar6 + 8;
        } while (local_2c < (int)param_2 / 2);
      }
      local_28 = local_28 + param_2 * 2;
      local_24 = local_24 + (param_2 >> 1);
      local_18 = local_18 + iVar1 * 2;
      local_20 = local_20 + (param_2 >> 1);
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  return 0;
}

