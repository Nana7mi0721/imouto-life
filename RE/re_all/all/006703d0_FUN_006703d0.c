
void FUN_006703d0(int *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  uint local_10;
  
  iVar4 = *(int *)(param_3 + 0x194);
  iVar8 = *param_1;
  iVar5 = *(int *)(param_3 + 400);
  bVar1 = *(byte *)((int)param_1 + 9);
  if (((bVar1 < 9) && (iVar5 != 0)) || ((bVar1 == 0x10 && (iVar4 != 0)))) {
    bVar10 = (byte)*(undefined4 *)(param_3 + 0x188);
    switch((char)param_1[2]) {
    case '\0':
      if ((bVar1 == 2) && (iVar8 != 0)) {
        local_10 = iVar8 + 3U >> 2;
        pbVar7 = param_2;
        do {
          uVar9 = (uint)*pbVar7;
          uVar11 = uVar9 & 0xc;
          uVar6 = uVar9 & 3;
          uVar12 = uVar9 & 0x30;
          uVar9 = uVar9 & 0xc0;
          *pbVar7 = (byte)((byte)(*(byte *)(((uVar11 * 4 | uVar11) << 2 | (int)uVar11 >> 2 | uVar11)
                                           + iVar5) & 0xcf |
                                 *(byte *)((((uVar6 * 4 | uVar6) << 2 | uVar6) << 2 | uVar6) + iVar5
                                          ) >> 2) >> 2 |
                          *(byte *)(((int)((int)uVar12 >> 2 | uVar12) >> 2 | uVar12 * 4 | uVar12) +
                                   iVar5) & 0xc3) >> 2 |
                    *(byte *)(((int)((int)((int)uVar9 >> 2 | uVar9) >> 2 | uVar9) >> 2 | uVar9) +
                             iVar5) & 0xc0;
          pbVar7 = pbVar7 + 1;
          local_10 = local_10 - 1;
        } while (local_10 != 0);
      }
      cVar2 = *(char *)((int)param_1 + 9);
      if (cVar2 == '\x04') {
        if (iVar8 != 0) {
          uVar6 = iVar8 + 1U >> 1;
          do {
            uVar9 = *param_2 & 0xf;
            uVar11 = *param_2 & 0xf0;
            *param_2 = *(byte *)(((int)uVar11 >> 4 | uVar11) + iVar5) & 0xf0 |
                       *(byte *)((uVar9 << 4 | uVar9) + iVar5) >> 4;
            param_2 = param_2 + 1;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
          return;
        }
      }
      else if (cVar2 == '\b') {
        if (iVar8 != 0) {
          do {
            iVar8 = iVar8 + -1;
            *param_2 = *(byte *)((uint)*param_2 + iVar5);
            param_2 = param_2 + 1;
          } while (iVar8 != 0);
          return;
        }
      }
      else if ((cVar2 == '\x10') && (iVar8 != 0)) {
        do {
          uVar3 = *(undefined2 *)
                   (*(int *)(iVar4 + (uint)(param_2[1] >> (bVar10 & 0x1f)) * 4) + (uint)*param_2 * 2
                   );
          param_2[1] = (byte)uVar3;
          *param_2 = (byte)((ushort)uVar3 >> 8);
          iVar8 = iVar8 + -1;
          param_2 = param_2 + 2;
        } while (iVar8 != 0);
      }
      break;
    case '\x02':
      if (bVar1 == 8) {
        if (iVar8 != 0) {
          do {
            *param_2 = *(byte *)((uint)*param_2 + iVar5);
            param_2[1] = *(byte *)((uint)param_2[1] + iVar5);
            iVar8 = iVar8 + -1;
            param_2[2] = *(byte *)((uint)param_2[2] + iVar5);
            param_2 = param_2 + 3;
          } while (iVar8 != 0);
          return;
        }
      }
      else if (iVar8 != 0) {
        do {
          uVar3 = *(undefined2 *)
                   (*(int *)(iVar4 + (uint)(param_2[1] >> (bVar10 & 0x1f)) * 4) + (uint)*param_2 * 2
                   );
          param_2[1] = (byte)uVar3;
          *param_2 = (byte)((ushort)uVar3 >> 8);
          uVar3 = *(undefined2 *)
                   (*(int *)(iVar4 + (uint)(param_2[3] >> (bVar10 & 0x1f)) * 4) +
                   (uint)param_2[2] * 2);
          param_2[3] = (byte)uVar3;
          param_2[2] = (byte)((ushort)uVar3 >> 8);
          uVar3 = *(undefined2 *)
                   (*(int *)(iVar4 + (uint)(param_2[5] >> (bVar10 & 0x1f)) * 4) +
                   (uint)param_2[4] * 2);
          param_2[5] = (byte)uVar3;
          param_2[4] = (byte)((ushort)uVar3 >> 8);
          iVar8 = iVar8 + -1;
          param_2 = param_2 + 6;
        } while (iVar8 != 0);
        return;
      }
      break;
    case '\x04':
      if (bVar1 == 8) {
        if (iVar8 != 0) {
          do {
            iVar8 = iVar8 + -1;
            *param_2 = *(byte *)((uint)*param_2 + iVar5);
            param_2 = param_2 + 2;
          } while (iVar8 != 0);
          return;
        }
      }
      else if (iVar8 != 0) {
        do {
          uVar3 = *(undefined2 *)
                   (*(int *)(iVar4 + (uint)(param_2[1] >> (bVar10 & 0x1f)) * 4) + (uint)*param_2 * 2
                   );
          param_2[1] = (byte)uVar3;
          *param_2 = (byte)((ushort)uVar3 >> 8);
          iVar8 = iVar8 + -1;
          param_2 = param_2 + 4;
        } while (iVar8 != 0);
        return;
      }
      break;
    case '\x06':
      if (bVar1 == 8) {
        if (iVar8 != 0) {
          do {
            *param_2 = *(byte *)((uint)*param_2 + iVar5);
            param_2[1] = *(byte *)((uint)param_2[1] + iVar5);
            iVar8 = iVar8 + -1;
            param_2[2] = *(byte *)((uint)param_2[2] + iVar5);
            param_2 = param_2 + 4;
          } while (iVar8 != 0);
          return;
        }
      }
      else if (iVar8 != 0) {
        do {
          uVar3 = *(undefined2 *)
                   (*(int *)(iVar4 + (uint)(param_2[1] >> (bVar10 & 0x1f)) * 4) + (uint)*param_2 * 2
                   );
          param_2[1] = (byte)uVar3;
          *param_2 = (byte)((ushort)uVar3 >> 8);
          uVar3 = *(undefined2 *)
                   (*(int *)(iVar4 + (uint)(param_2[3] >> (bVar10 & 0x1f)) * 4) +
                   (uint)param_2[2] * 2);
          param_2[3] = (byte)uVar3;
          param_2[2] = (byte)((ushort)uVar3 >> 8);
          uVar3 = *(undefined2 *)
                   (*(int *)(iVar4 + (uint)(param_2[5] >> (bVar10 & 0x1f)) * 4) +
                   (uint)param_2[4] * 2);
          param_2[5] = (byte)uVar3;
          param_2[4] = (byte)((ushort)uVar3 >> 8);
          iVar8 = iVar8 + -1;
          param_2 = param_2 + 8;
        } while (iVar8 != 0);
        return;
      }
    }
  }
  return;
}

