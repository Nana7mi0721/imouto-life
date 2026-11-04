
void FUN_0066ed50(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  
  bVar4 = *(byte *)((int)param_1 + 9);
  iVar2 = *param_1;
  if ((7 < bVar4) && (bVar1 = *(byte *)(param_1 + 2), (bVar1 & 2) == 0)) {
    if (bVar1 == 0) {
      if (bVar4 == 8) {
        puVar6 = (undefined1 *)(iVar2 + -1 + param_2);
        puVar5 = puVar6 + iVar2 * 2;
        if (iVar2 != 0) {
          iVar7 = iVar2;
          do {
            *puVar5 = *puVar6;
            puVar5[-1] = *puVar6;
            puVar5[-2] = *puVar6;
            puVar5 = puVar5 + -3;
            puVar6 = puVar6 + -1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
      }
      else {
        puVar6 = (undefined1 *)(param_2 + -1 + iVar2 * 2);
        puVar5 = puVar6 + iVar2 * 4;
        if (iVar2 != 0) {
          iVar7 = iVar2;
          do {
            *puVar5 = *puVar6;
            puVar5[-1] = puVar6[-1];
            puVar5[-2] = *puVar6;
            puVar5[-3] = puVar6[-1];
            puVar5[-4] = *puVar6;
            puVar5[-5] = puVar6[-1];
            puVar5 = puVar5 + -6;
            puVar6 = puVar6 + -2;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
      }
    }
    else if (bVar1 == 4) {
      if (bVar4 == 8) {
        puVar6 = (undefined1 *)(param_2 + -1 + iVar2 * 2);
        puVar5 = puVar6 + iVar2 * 2;
        if (iVar2 != 0) {
          iVar7 = iVar2;
          do {
            *puVar5 = *puVar6;
            puVar5[-1] = puVar6[-1];
            puVar5[-2] = puVar6[-1];
            puVar5[-3] = puVar6[-1];
            puVar5 = puVar5 + -4;
            puVar6 = puVar6 + -2;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
      }
      else {
        puVar6 = (undefined1 *)(param_2 + -1 + iVar2 * 4);
        puVar5 = puVar6 + iVar2 * 4;
        if (iVar2 != 0) {
          iVar7 = iVar2;
          do {
            *puVar5 = *puVar6;
            puVar5[-1] = puVar6[-1];
            puVar5[-2] = puVar6[-2];
            puVar5[-3] = puVar6[-3];
            puVar5[-4] = puVar6[-2];
            puVar5[-5] = puVar6[-3];
            puVar5[-6] = puVar6[-2];
            puVar5[-7] = puVar6[-3];
            puVar5 = puVar5 + -8;
            puVar6 = puVar6 + -4;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
      }
    }
    cVar3 = *(char *)((int)param_1 + 10) + '\x02';
    *(char *)((int)param_1 + 10) = cVar3;
    *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 2;
    bVar4 = *(char *)((int)param_1 + 9) * cVar3;
    *(byte *)((int)param_1 + 0xb) = bVar4;
    if (7 < bVar4) {
      param_1[1] = (uint)(bVar4 >> 3) * iVar2;
      return;
    }
    param_1[1] = (uint)bVar4 * iVar2 + 7 >> 3;
  }
  return;
}

