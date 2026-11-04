
undefined4 FUN_005435e0(byte *param_1,int param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  byte *pbVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  int local_c;
  
  iVar1 = *(int *)(param_4 + 0x430);
  if (0 < (int)param_3) {
    param_1 = (byte *)((int)param_1 + 1);
    local_c = (int)param_3;
    param_3 = (undefined1 *)(*(int *)(param_4 + 0x434) + 2);
    do {
      if (0 < param_2 / 2) {
        pbVar2 = param_1;
        puVar9 = param_3;
        param_4 = param_2 / 2;
        do {
          iVar6 = (pbVar2[-1] - 0x80) * 0xe2d0;
          iVar5 = (pbVar2[1] - 0x80) * 0xb374;
          iVar4 = (pbVar2[-1] - 0x80) * -0x2c08 + (pbVar2[1] - 0x80) * -0x5b64;
          iVar7 = (uint)*pbVar2 * 0x8000;
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
          puVar9[-2] = uVar3;
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
          puVar9[-1] = uVar3;
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
          *puVar9 = uVar3;
          puVar9[1] = 0xff;
          iVar8 = (uint)pbVar2[2] * 0x8000;
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
          puVar9[2] = uVar3;
          iVar4 = iVar8 + iVar4;
          if (iVar4 < 0) {
            uVar3 = 0;
          }
          else if (iVar4 < 0x7f8001) {
            uVar3 = (undefined1)(iVar4 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          puVar9[3] = uVar3;
          iVar8 = iVar8 + iVar5;
          if (iVar8 < 0) {
            uVar3 = 0;
          }
          else if (iVar8 < 0x7f8001) {
            uVar3 = (undefined1)(iVar8 >> 0xf);
          }
          else {
            uVar3 = 0xff;
          }
          puVar9[4] = uVar3;
          puVar9[5] = 0xff;
          puVar9 = puVar9 + 8;
          pbVar2 = pbVar2 + 4;
          param_4 = param_4 + -1;
        } while (param_4 != 0);
      }
      param_3 = param_3 + iVar1;
      param_1 = param_1 + param_2 * 2;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  return 0;
}

