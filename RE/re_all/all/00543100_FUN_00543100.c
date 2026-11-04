
undefined4 FUN_00543100(int param_1,int param_2,int param_3,byte *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte *local_2c;
  int local_28;
  undefined1 *local_24;
  byte *local_1c;
  int local_18;
  
  local_1c = (byte *)(param_2 * param_3 + param_1);
  iVar1 = *(int *)((int)param_4 + 0x430);
  local_18 = param_3 / 2;
  if (0 < local_18) {
    local_24 = (undefined1 *)(*(int *)((int)param_4 + 0x434) + 2);
    do {
      if (0 < param_2 / 2) {
        local_2c = (byte *)(param_2 + param_1);
        puVar2 = local_24;
        param_4 = local_1c;
        local_28 = param_2 / 2;
        do {
          iVar6 = (*param_4 - 0x80) * 0xe2d0;
          iVar5 = (param_4[1] - 0x80) * 0xb374;
          iVar4 = (*param_4 - 0x80) * -0x2c08 + (param_4[1] - 0x80) * -0x5b64;
          iVar7 = (uint)param_4[param_1 - (int)local_1c] * 0x8000;
          iVar8 = iVar7 + iVar6;
          if (iVar8 < 0) {
            uVar3 = 0;
          }
          else if (iVar8 < 0x7f8001) {
            uVar3 = (undefined1)(iVar8 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          puVar2[-2] = uVar3;
          iVar8 = iVar7 + iVar4;
          if (iVar8 < 0) {
            uVar3 = 0;
          }
          else if (iVar8 < 0x7f8001) {
            uVar3 = (undefined1)(iVar8 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          iVar7 = iVar7 + iVar5;
          puVar2[-1] = uVar3;
          if (iVar7 < 0) {
            uVar3 = 0;
          }
          else if (iVar7 < 0x7f8001) {
            uVar3 = (undefined1)(iVar7 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          *puVar2 = uVar3;
          puVar2[1] = 0xff;
          iVar7 = (uint)local_2c[1 - param_2] * 0x8000;
          iVar8 = iVar7 + iVar6;
          if (iVar8 < 0) {
            uVar3 = 0;
          }
          else if (iVar8 < 0x7f8001) {
            uVar3 = (undefined1)(iVar8 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          puVar2[2] = uVar3;
          iVar8 = iVar7 + iVar4;
          if (iVar8 < 0) {
            uVar3 = 0;
          }
          else if (iVar8 < 0x7f8001) {
            uVar3 = (undefined1)(iVar8 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          puVar2[3] = uVar3;
          iVar7 = iVar7 + iVar5;
          if (iVar7 < 0) {
            uVar3 = 0;
          }
          else if (iVar7 < 0x7f8001) {
            uVar3 = (undefined1)(iVar7 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          puVar2[4] = uVar3;
          puVar2[5] = 0xff;
          iVar7 = (uint)*local_2c * 0x8000;
          iVar8 = iVar7 + iVar6;
          if (iVar8 < 0) {
            uVar3 = 0;
          }
          else if (iVar8 < 0x7f8001) {
            uVar3 = (undefined1)(iVar8 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          puVar2[iVar1 + -2] = uVar3;
          iVar8 = iVar7 + iVar4;
          if (iVar8 < 0) {
            uVar3 = 0;
          }
          else if (iVar8 < 0x7f8001) {
            uVar3 = (undefined1)(iVar8 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          puVar2[iVar1 + -1] = uVar3;
          iVar7 = iVar7 + iVar5;
          if (iVar7 < 0) {
            uVar3 = 0;
          }
          else if (iVar7 < 0x7f8001) {
            uVar3 = (undefined1)(iVar7 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          puVar2[iVar1] = uVar3;
          puVar2[iVar1 + 1] = 0xff;
          iVar8 = (uint)local_2c[1] * 0x8000;
          iVar6 = iVar8 + iVar6;
          if (iVar6 < 0) {
            uVar3 = 0;
          }
          else if (iVar6 < 0x7f8001) {
            uVar3 = (undefined1)(iVar6 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          puVar2[iVar1 + 2] = uVar3;
          iVar4 = iVar4 + iVar8;
          if (iVar4 < 0) {
            uVar3 = 0;
          }
          else if (iVar4 < 0x7f8001) {
            uVar3 = (undefined1)(iVar4 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          puVar2[iVar1 + 3] = uVar3;
          iVar5 = iVar5 + iVar8;
          if (iVar5 < 0) {
            uVar3 = 0;
          }
          else if (iVar5 < 0x7f8001) {
            uVar3 = (undefined1)(iVar5 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          param_4 = param_4 + 2;
          puVar2[iVar1 + 4] = uVar3;
          puVar2[iVar1 + 5] = 0xff;
          local_2c = local_2c + 2;
          puVar2 = puVar2 + 8;
          local_28 = local_28 + -1;
        } while (local_28 != 0);
      }
      param_1 = param_1 + param_2 * 2;
      local_1c = local_1c + param_2;
      local_24 = local_24 + iVar1 * 2;
      local_18 = local_18 + -1;
    } while (local_18 != 0);
  }
  return 0;
}

