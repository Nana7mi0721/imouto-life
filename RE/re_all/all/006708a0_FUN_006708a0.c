
void FUN_006708a0(uint *param_1,uint param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  
  iVar3 = param_2;
  uVar8 = *param_1;
  if ((char)param_1[2] == '\x03') {
    bVar2 = *(byte *)((int)param_1 + 9);
    if (bVar2 < 8) {
      if (bVar2 == 1) {
        pbVar9 = (byte *)((uVar8 - 1 >> 3) + param_2);
        iVar4 = 7 - (uVar8 - 1 & 7);
        pbVar7 = (byte *)((uVar8 - 1) + param_2);
        if (uVar8 != 0) {
          param_2 = uVar8;
          do {
            *pbVar7 = *pbVar9 >> ((byte)iVar4 & 0x1f) & 1;
            if (iVar4 == 7) {
              iVar4 = 0;
              pbVar9 = pbVar9 + -1;
            }
            else {
              iVar4 = iVar4 + 1;
            }
            pbVar7 = pbVar7 + -1;
            param_2 = param_2 - 1;
          } while (param_2 != 0);
        }
      }
      else if (bVar2 == 2) {
        pbVar9 = (byte *)((uVar8 - 1 >> 2) + param_2);
        iVar4 = (3 - (uVar8 - 1 & 3)) * 2;
        pbVar7 = (byte *)((uVar8 - 1) + param_2);
        if (uVar8 != 0) {
          param_2 = uVar8;
          do {
            *pbVar7 = *pbVar9 >> ((byte)iVar4 & 0x1f) & 3;
            if (iVar4 == 6) {
              iVar4 = 0;
              pbVar9 = pbVar9 + -1;
            }
            else {
              iVar4 = iVar4 + 2;
            }
            pbVar7 = pbVar7 + -1;
            param_2 = param_2 - 1;
          } while (param_2 != 0);
        }
      }
      else if (bVar2 == 4) {
        pbVar9 = (byte *)((uVar8 - 1 >> 1) + param_2);
        iVar4 = (uVar8 & 1) << 2;
        pbVar7 = (byte *)((uVar8 - 1) + param_2);
        if (uVar8 != 0) {
          param_2 = uVar8;
          do {
            *pbVar7 = *pbVar9 >> ((byte)iVar4 & 0x1f) & 0xf;
            if (iVar4 == 4) {
              iVar4 = 0;
              pbVar9 = pbVar9 + -1;
            }
            else {
              iVar4 = iVar4 + 4;
            }
            pbVar7 = pbVar7 + -1;
            param_2 = param_2 - 1;
          } while (param_2 != 0);
        }
      }
      *(undefined1 *)((int)param_1 + 9) = 8;
      *(undefined1 *)((int)param_1 + 0xb) = 8;
      param_1[1] = uVar8;
    }
    if (*(char *)((int)param_1 + 9) == '\b') {
      pbVar7 = (byte *)((uVar8 - 1) + iVar3);
      if (0 < param_5) {
        uVar1 = uVar8 * 4;
        puVar6 = (undefined1 *)((uVar1 - 1) + iVar3);
        if (uVar8 != 0) {
          do {
            if ((int)(uint)*pbVar7 < param_5) {
              *puVar6 = *(undefined1 *)((uint)*pbVar7 + param_4);
            }
            else {
              *puVar6 = 0xff;
            }
            puVar6[-1] = *(undefined1 *)((uint)*pbVar7 * 3 + 2 + param_3);
            puVar5 = puVar6 + -3;
            puVar6[-2] = *(undefined1 *)((uint)*pbVar7 * 3 + 1 + param_3);
            bVar2 = *pbVar7;
            puVar6 = puVar6 + -4;
            pbVar7 = pbVar7 + -1;
            uVar8 = uVar8 - 1;
            *puVar5 = *(undefined1 *)(param_3 + (uint)bVar2 * 3);
          } while (uVar8 != 0);
        }
        param_1[1] = uVar1;
        *(undefined1 *)((int)param_1 + 9) = 8;
        *(undefined1 *)((int)param_1 + 0xb) = 0x20;
        *(undefined1 *)(param_1 + 2) = 6;
        *(undefined1 *)((int)param_1 + 10) = 4;
        return;
      }
      uVar1 = uVar8 * 3;
      puVar6 = (undefined1 *)((uVar1 - 1) + iVar3);
      if (uVar8 != 0) {
        do {
          *puVar6 = *(undefined1 *)((uint)*pbVar7 * 3 + 2 + param_3);
          puVar5 = puVar6 + -2;
          puVar6[-1] = *(undefined1 *)((uint)*pbVar7 * 3 + 1 + param_3);
          bVar2 = *pbVar7;
          puVar6 = puVar6 + -3;
          pbVar7 = pbVar7 + -1;
          uVar8 = uVar8 - 1;
          *puVar5 = *(undefined1 *)(param_3 + (uint)bVar2 * 3);
        } while (uVar8 != 0);
      }
      *(undefined1 *)((int)param_1 + 9) = 8;
      *(undefined1 *)((int)param_1 + 0xb) = 0x18;
      param_1[1] = uVar1;
      *(undefined1 *)(param_1 + 2) = 2;
      *(undefined1 *)((int)param_1 + 10) = 3;
    }
  }
  return;
}

