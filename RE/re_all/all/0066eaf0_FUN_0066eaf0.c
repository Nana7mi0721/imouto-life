
void FUN_0066eaf0(uint *param_1,int param_2,uint param_3,byte param_4)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  byte bVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  
  uVar1 = *param_1;
  uVar5 = param_3 >> 8;
  bVar4 = (byte)(param_3 >> 8);
  uVar3 = (undefined1)param_3;
  if ((char)param_1[2] == '\0') {
    if (*(char *)((int)param_1 + 9) == '\b') {
      puVar6 = (undefined1 *)(uVar1 + param_2);
      puVar7 = puVar6 + uVar1;
      if ((param_4 & 0x80) == 0) {
        if (uVar1 != 0) {
          uVar5 = uVar1;
          do {
            puVar8 = puVar6 + -1;
            puVar6 = puVar6 + -1;
            puVar7[-1] = *puVar8;
            puVar7 = puVar7 + -2;
            uVar5 = uVar5 - 1;
            *puVar7 = uVar3;
          } while (uVar5 != 0);
        }
        *(undefined1 *)((int)param_1 + 10) = 2;
        *(undefined1 *)((int)param_1 + 0xb) = 0x10;
        param_1[1] = uVar1 * 2;
        return;
      }
      if (1 < uVar1) {
        iVar2 = uVar1 - 1;
        do {
          puVar6 = puVar6 + -1;
          puVar7[-1] = uVar3;
          puVar7 = puVar7 + -2;
          iVar2 = iVar2 + -1;
          *puVar7 = *puVar6;
        } while (iVar2 != 0);
      }
      puVar7[-1] = uVar3;
      *(undefined1 *)((int)param_1 + 10) = 2;
      *(undefined1 *)((int)param_1 + 0xb) = 0x10;
      param_1[1] = uVar1 * 2;
      return;
    }
    if (*(char *)((int)param_1 + 9) == '\x10') {
      puVar6 = (undefined1 *)(param_2 + uVar1 * 2);
      puVar7 = puVar6 + uVar1 * 2;
      if ((param_4 & 0x80) == 0) {
        if (uVar1 != 0) {
          uVar5 = uVar1;
          do {
            puVar8 = puVar6 + -1;
            puVar6 = puVar6 + -2;
            puVar7[-1] = *puVar8;
            puVar7[-2] = *puVar6;
            puVar7[-3] = bVar4;
            puVar7 = puVar7 + -4;
            uVar5 = uVar5 - 1;
            *puVar7 = uVar3;
          } while (uVar5 != 0);
        }
        *(undefined1 *)((int)param_1 + 10) = 2;
        *(undefined1 *)((int)param_1 + 0xb) = 0x20;
        param_1[1] = uVar1 << 2;
        return;
      }
      if (1 < uVar1) {
        iVar2 = uVar1 - 1;
        do {
          puVar7[-1] = (char)uVar5;
          puVar8 = puVar6 + -1;
          puVar7[-2] = uVar3;
          puVar6 = puVar6 + -2;
          puVar7[-3] = *puVar8;
          puVar7 = puVar7 + -4;
          iVar2 = iVar2 + -1;
          *puVar7 = *puVar6;
          uVar5 = (uint)bVar4;
        } while (iVar2 != 0);
      }
      puVar7[-1] = bVar4;
      puVar7[-2] = uVar3;
      *(undefined1 *)((int)param_1 + 10) = 2;
      *(undefined1 *)((int)param_1 + 0xb) = 0x20;
      param_1[1] = uVar1 << 2;
      return;
    }
  }
  else if ((char)param_1[2] == '\x02') {
    if (*(char *)((int)param_1 + 9) == '\b') {
      param_2 = param_2 + uVar1 * 2;
      if ((param_4 & 0x80) == 0) {
        puVar7 = (undefined1 *)(uVar1 + param_2);
        puVar6 = puVar7 + uVar1;
        if (uVar1 != 0) {
          uVar5 = uVar1;
          do {
            puVar8 = puVar7 + -2;
            puVar6[-1] = puVar7[-1];
            puVar7 = puVar7 + -3;
            puVar6[-2] = *puVar8;
            puVar6[-3] = *puVar7;
            puVar6 = puVar6 + -4;
            uVar5 = uVar5 - 1;
            *puVar6 = uVar3;
          } while (uVar5 != 0);
        }
        *(undefined1 *)((int)param_1 + 10) = 4;
        *(undefined1 *)((int)param_1 + 0xb) = 0x20;
        param_1[1] = uVar1 << 2;
        return;
      }
      puVar7 = (undefined1 *)(uVar1 + param_2);
      puVar6 = puVar7 + uVar1;
      if (1 < uVar1) {
        iVar2 = uVar1 - 1;
        do {
          puVar6[-1] = uVar3;
          puVar8 = puVar7 + -2;
          puVar6[-2] = puVar7[-1];
          puVar7 = puVar7 + -3;
          puVar6[-3] = *puVar8;
          puVar6 = puVar6 + -4;
          iVar2 = iVar2 + -1;
          *puVar6 = *puVar7;
        } while (iVar2 != 0);
      }
      puVar6[-1] = uVar3;
      *(undefined1 *)((int)param_1 + 10) = 4;
      *(undefined1 *)((int)param_1 + 0xb) = 0x20;
      param_1[1] = uVar1 << 2;
      return;
    }
    if (*(char *)((int)param_1 + 9) == '\x10') {
      puVar6 = (undefined1 *)(param_2 + uVar1 * 6);
      puVar7 = puVar6 + uVar1 * 2;
      if ((param_4 & 0x80) != 0) {
        if (1 < uVar1) {
          iVar2 = uVar1 - 1;
          do {
            puVar7[-1] = (char)uVar5;
            puVar7[-2] = uVar3;
            puVar7[-3] = puVar6[-1];
            puVar7[-4] = puVar6[-2];
            puVar7[-5] = puVar6[-3];
            puVar8 = puVar6 + -5;
            puVar7[-6] = puVar6[-4];
            puVar6 = puVar6 + -6;
            puVar7[-7] = *puVar8;
            puVar7 = puVar7 + -8;
            iVar2 = iVar2 + -1;
            *puVar7 = *puVar6;
            uVar5 = (uint)bVar4;
          } while (iVar2 != 0);
        }
        puVar7[-1] = bVar4;
        puVar7[-2] = uVar3;
        *(undefined1 *)((int)param_1 + 10) = 4;
        *(undefined1 *)((int)param_1 + 0xb) = 0x40;
        param_1[1] = uVar1 << 3;
        return;
      }
      if (uVar1 != 0) {
        uVar5 = uVar1;
        do {
          puVar7[-1] = puVar6[-1];
          puVar7[-2] = puVar6[-2];
          puVar7[-3] = puVar6[-3];
          puVar8 = puVar6 + -5;
          puVar7[-4] = puVar6[-4];
          puVar6 = puVar6 + -6;
          puVar7[-5] = *puVar8;
          puVar7[-6] = *puVar6;
          puVar7[-7] = bVar4;
          puVar7 = puVar7 + -8;
          uVar5 = uVar5 - 1;
          *puVar7 = uVar3;
        } while (uVar5 != 0);
      }
      *(undefined1 *)((int)param_1 + 10) = 4;
      *(undefined1 *)((int)param_1 + 0xb) = 0x40;
      param_1[1] = uVar1 << 3;
    }
  }
  return;
}

