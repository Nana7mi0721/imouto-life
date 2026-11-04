
void FUN_00581490(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 byte *param_7,undefined4 param_8,undefined4 param_9,int param_10)

{
  int iVar1;
  uint3 *puVar2;
  uint uVar3;
  uint *puVar4;
  ushort *puVar5;
  int iVar6;
  byte bVar7;
  int *piVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_10 = param_4;
  local_8 = param_4 + param_6;
  local_c = param_5;
  local_4 = param_5 + (int)param_7;
  iVar1 = *(int *)(param_3 + 0x14);
  if ((*(int *)(iVar1 + 0x20) == 3) || (*(int *)(iVar1 + 0x20) == 2)) {
    FUN_00549b20(*(undefined4 *)(param_3 + 0xc),*(undefined4 *)(iVar1 + 0xc),
                 *(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(param_1 + 0x434),
                 *(undefined4 *)(param_1 + 0x430),param_1,0,0,0,param_8,param_9,&local_10,0,0,0,0,1,
                 1,0,0);
  }
  else if (param_2 == 0) {
    iVar1 = FUN_00549b20(*(undefined4 *)(param_3 + 0xc),*(undefined4 *)(iVar1 + 0xc),
                         *(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(param_1 + 0x434),
                         *(undefined4 *)(param_1 + 0x430),param_1,0,0,0,param_8,param_9,&local_10,0,
                         param_10,*(undefined4 *)(iVar1 + 0x1c),0,0,0,0,0);
    if (iVar1 < 0) {
      return;
    }
    if (*(int *)(*(int *)(param_3 + 0x14) + 0x24) == 1) {
      *(int *)(*(int *)(param_3 + 0x14) + 0x28) = iVar1 + 1;
    }
  }
  else {
    iVar1 = FUN_00549b20(*(undefined4 *)(param_3 + 0xc),*(undefined4 *)(iVar1 + 0xc),
                         *(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(param_1 + 0x434),
                         *(undefined4 *)(param_1 + 0x430),param_1,*(undefined4 *)(param_2 + 0x434),
                         *(undefined4 *)(param_2 + 0x430),param_2,param_8,param_9,&local_10,0,
                         param_10,*(undefined4 *)(iVar1 + 0x1c),0,0,0,0,0);
    if (iVar1 < 0) {
      return;
    }
  }
  iVar1 = *(int *)(param_3 + 0x14);
  if (*(int *)(iVar1 + 0x24) == 1) {
    puVar4 = *(uint **)(iVar1 + 0x3c);
    puVar2 = (uint3 *)(param_1 + 0x28);
    iVar12 = 0x40;
    if (*(int *)(iVar1 + 0x20) == 0) {
      do {
        *(ushort *)puVar4 =
             ((*(byte *)((int)puVar2 + 2) & 0xfff8) << 5 | *(byte *)((int)puVar2 + 1) & 0xfffc) * 8
             | (ushort)(byte)((byte)*puVar2 >> 3);
        *(ushort *)((int)puVar4 + 2) =
             ((*(byte *)((int)puVar2 + 6) & 0xfff8) << 5 | *(byte *)((int)puVar2 + 5) & 0xfffc) * 8
             | (ushort)(byte)((byte)puVar2[1] >> 3);
        *(ushort *)(puVar4 + 1) =
             ((*(byte *)((int)puVar2 + 10) & 0xfff8) << 5 | *(byte *)((int)puVar2 + 9) & 0xfffc) * 8
             | (ushort)(byte)((byte)puVar2[2] >> 3);
        *(ushort *)((int)puVar4 + 6) =
             ((*(byte *)((int)puVar2 + 0xe) & 0xfff8) << 5 | *(byte *)((int)puVar2 + 0xd) & 0xfffc)
             * 8 | (ushort)(byte)((byte)puVar2[3] >> 3);
        puVar2 = puVar2 + 4;
        puVar4 = puVar4 + 2;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      uVar14 = 0x200;
    }
    else {
      do {
        *puVar4 = (uint)*puVar2;
        puVar4[1] = (uint)puVar2[1];
        puVar4[2] = (uint)puVar2[2];
        iVar12 = iVar12 + -1;
        puVar4[3] = (uint)puVar2[3];
        puVar2 = puVar2 + 4;
        puVar4 = puVar4 + 4;
      } while (iVar12 != 0);
      uVar14 = 0x400;
    }
    FUN_0056d420(*(undefined4 *)(*(int *)(param_3 + 0x14) + 0x40),
                 *(undefined4 *)(*(int *)(param_3 + 0x14) + 0x3c),uVar14);
  }
  iVar1 = *(int *)(param_3 + 0x14);
  if (((*(int *)(iVar1 + 0x20) == 0) || (*(int *)(iVar1 + 0x20) == 1)) &&
     (*(int *)(iVar1 + 0x2c) == 0)) {
    *(uint *)(iVar1 + 0x18) = (uint)(param_10 != 0);
  }
  *(undefined4 *)(*(int *)(param_3 + 0x14) + 0x30) = 0;
  *(undefined4 *)(*(int *)(param_3 + 0x14) + 0x34) = 0;
  if ((param_6 == *(int *)(param_3 + 4)) && (param_7 == (byte *)*(int *)(param_3 + 8))) {
    iVar1 = *(int *)(param_3 + 0x14);
    if (((*(int *)(iVar1 + 0x20) == 0) || (*(int *)(iVar1 + 0x20) == 1)) &&
       (*(int *)(iVar1 + 0x4c) != 0)) {
      *(undefined4 *)(iVar1 + 0x34) = 1;
      iVar1 = *(int *)(param_3 + 0x14);
      uVar9 = *(uint *)(iVar1 + 0x1c);
      if ((*(int *)(iVar1 + 0x2c) == 1) && (*(int *)(iVar1 + 0x48) != 0)) {
        *(undefined4 *)(iVar1 + 0x30) = 1;
        piVar8 = *(int **)(param_3 + 0x10);
        puVar5 = *(ushort **)(param_3 + 0xc);
        iVar1 = *(int *)(*(int *)(param_3 + 0x14) + 0xc) + *(int *)(param_3 + 4) * -4;
        param_7 = *(byte **)(param_3 + 8);
        if (*(int *)(*(int *)(param_3 + 0x14) + 0x20) == 0) {
          do {
            param_4 = param_6;
            do {
              uVar3 = (uint)*puVar5;
              uVar13 = (uint)(byte)puVar5[1];
              *piVar8 = (int)((uVar3 & 0x7e0) * uVar13 & 0x7e000 | (uVar3 & 0x1f) * uVar13 & 0x1f00
                             | (uVar3 & 0xf800) * uVar13 & 0xf80000) >> 8;
              *(byte *)((int)piVar8 + 2) = (byte)puVar5[1];
              puVar5 = puVar5 + 2;
              piVar8 = piVar8 + 1;
              param_4 = param_4 + -1;
            } while (param_4 != 0);
            puVar5 = (ushort *)((int)puVar5 + iVar1);
            piVar8 = (int *)((int)piVar8 + iVar1);
            param_7 = (byte *)((int)param_7 + -1);
          } while (param_7 != (byte *)0x0);
        }
        else {
          do {
            iVar12 = param_6;
            do {
              *(char *)piVar8 = (char)((uint)*(byte *)((int)puVar5 + 3) * (uint)(byte)*puVar5 >> 8);
              *(char *)((int)piVar8 + 1) =
                   (char)((uint)*(byte *)((int)puVar5 + 1) * (uint)*(byte *)((int)puVar5 + 3) >> 8);
              *(char *)((int)piVar8 + 2) =
                   (char)((uint)*(byte *)((int)puVar5 + 3) * (uint)(byte)puVar5[1] >> 8);
              *(byte *)((int)piVar8 + 3) = (byte)puVar5[1];
              puVar5 = puVar5 + 2;
              piVar8 = piVar8 + 1;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
            puVar5 = (ushort *)((int)puVar5 + iVar1);
            piVar8 = (int *)((int)piVar8 + iVar1);
            param_7 = (byte *)((int)param_7 + -1);
          } while (param_7 != (byte *)0x0);
        }
      }
      iVar1 = *(int *)(param_3 + 0x14);
      pbVar11 = *(byte **)(iVar1 + 0x4c);
      puVar4 = *(uint **)(param_3 + 0xc);
      iVar12 = *(int *)(iVar1 + 0xc) -
               (uint)*(byte *)(*(int *)(iVar1 + 0x14) + 4) * *(int *)(param_3 + 4);
      param_7 = pbVar11;
      if (*(int *)(iVar1 + 0x24) == 1) {
        iVar1 = *(int *)(param_3 + 8);
        do {
          iVar6 = param_6;
          pbVar11 = param_7;
          do {
            param_7 = pbVar11;
            uVar3 = *puVar4;
            puVar4 = (uint *)((int)puVar4 + 1);
            uVar13 = 1;
            if ((byte)uVar3 == uVar9) {
              iVar6 = iVar6 + -1;
              if (iVar6 != 0) {
                do {
                  if ((byte)*puVar4 != uVar9) break;
                  puVar4 = (uint *)((int)puVar4 + 1);
                  uVar13 = uVar13 + 1;
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0 && uVar13 < 0x40);
              }
              bVar7 = (char)uVar13 - 1;
            }
            else {
              iVar6 = iVar6 + -1;
              if (iVar6 != 0) {
                do {
                  if ((byte)*puVar4 == uVar9) break;
                  puVar4 = (uint *)((int)puVar4 + 1);
                  uVar13 = uVar13 + 1;
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0 && uVar13 < 0x40);
              }
              bVar7 = (char)uVar13 - 1U | 0x40;
            }
            *param_7 = bVar7;
            pbVar11 = param_7 + 1;
          } while (iVar6 != 0);
          puVar4 = (uint *)((int)puVar4 + iVar12);
          param_7[1] = 0xc0;
          param_7 = param_7 + 2;
          iVar1 = iVar1 + -1;
          if (iVar1 == 0) {
            return;
          }
        } while( true );
      }
      if (*(int *)(iVar1 + 0x2c) == 0) {
        if (*(int *)(iVar1 + 0x20) != 0) {
          iVar1 = *(int *)(param_3 + 8);
          do {
            iVar6 = param_6;
            pbVar11 = param_7;
            do {
              param_7 = pbVar11;
              uVar3 = *puVar4;
              puVar4 = puVar4 + 1;
              uVar13 = 1;
              if (uVar3 == uVar9) {
                iVar6 = iVar6 + -1;
                if (iVar6 != 0) {
                  do {
                    if (*puVar4 != uVar9) break;
                    puVar4 = puVar4 + 1;
                    uVar13 = uVar13 + 1;
                    iVar6 = iVar6 + -1;
                  } while (iVar6 != 0 && uVar13 < 0x40);
                }
                bVar7 = (char)uVar13 - 1;
              }
              else {
                iVar6 = iVar6 + -1;
                if (iVar6 != 0) {
                  do {
                    if (*puVar4 == uVar9) break;
                    puVar4 = puVar4 + 1;
                    uVar13 = uVar13 + 1;
                    iVar6 = iVar6 + -1;
                  } while (iVar6 != 0 && uVar13 < 0x40);
                }
                bVar7 = (char)uVar13 - 1U | 0x40;
              }
              *param_7 = bVar7;
              pbVar11 = param_7 + 1;
            } while (iVar6 != 0);
            puVar4 = (uint *)((int)puVar4 + iVar12);
            param_7[1] = 0xc0;
            param_7 = param_7 + 2;
            iVar1 = iVar1 + -1;
            if (iVar1 == 0) {
              return;
            }
          } while( true );
        }
        param_7 = *(byte **)(param_3 + 8);
        do {
          iVar1 = param_6;
          do {
            pbVar10 = pbVar11;
            uVar3 = *puVar4;
            puVar4 = (uint *)((int)puVar4 + 2);
            uVar13 = 1;
            if ((ushort)uVar3 == uVar9) {
              iVar1 = iVar1 + -1;
              if (iVar1 != 0) {
                do {
                  if ((ushort)*puVar4 != uVar9) break;
                  uVar13 = uVar13 + 1;
                  puVar4 = (uint *)((int)puVar4 + 2);
                  iVar1 = iVar1 + -1;
                } while (iVar1 != 0 && uVar13 < 0x40);
              }
              bVar7 = (char)uVar13 - 1;
            }
            else {
              iVar1 = iVar1 + -1;
              if (iVar1 != 0) {
                do {
                  if ((ushort)*puVar4 == uVar9) break;
                  uVar13 = uVar13 + 1;
                  puVar4 = (uint *)((int)puVar4 + 2);
                  iVar1 = iVar1 + -1;
                } while (iVar1 != 0 && uVar13 < 0x40);
              }
              bVar7 = (char)uVar13 - 1U | 0x40;
            }
            *pbVar10 = bVar7;
            pbVar11 = pbVar10 + 1;
          } while (iVar1 != 0);
          puVar4 = (uint *)((int)puVar4 + iVar12);
          pbVar10[1] = 0xc0;
          pbVar11 = pbVar10 + 2;
          param_7 = (byte *)((int)param_7 + -1);
          if (param_7 == (byte *)0x0) {
            return;
          }
        } while( true );
      }
      param_7 = *(byte **)(param_3 + 8);
      iVar1 = (*(int *)(iVar1 + 0x20) != 0) + 2;
      do {
        iVar6 = param_6;
        do {
          pbVar10 = pbVar11;
          pbVar11 = (byte *)(iVar1 + (int)puVar4);
          puVar4 = puVar4 + 1;
          if (*pbVar11 == 0) {
            iVar6 = iVar6 + -1;
            uVar9 = 1;
            if (iVar6 != 0) {
              do {
                if (*(byte *)(iVar1 + (int)puVar4) != 0) break;
                uVar9 = uVar9 + 1;
                puVar4 = puVar4 + 1;
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0 && uVar9 < 0x40);
            }
            bVar7 = (char)uVar9 - 1;
          }
          else {
            uVar9 = 1;
            if (*pbVar11 == 0xff) {
              iVar6 = iVar6 + -1;
              if (iVar6 != 0) {
                do {
                  if (*(byte *)(iVar1 + (int)puVar4) != 0xff) break;
                  uVar9 = uVar9 + 1;
                  puVar4 = puVar4 + 1;
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0 && uVar9 < 0x40);
              }
              bVar7 = (char)uVar9 - 1U | 0x40;
            }
            else {
              iVar6 = iVar6 + -1;
              if (iVar6 != 0) {
                do {
                  if ((*(byte *)(iVar1 + (int)puVar4) == 0) ||
                     (*(byte *)(iVar1 + (int)puVar4) == 0xff)) break;
                  uVar9 = uVar9 + 1;
                  puVar4 = puVar4 + 1;
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0 && uVar9 < 0x40);
              }
              bVar7 = (char)uVar9 - 1U | 0x80;
            }
          }
          *pbVar10 = bVar7;
          pbVar11 = pbVar10 + 1;
        } while (iVar6 != 0);
        puVar4 = (uint *)((int)puVar4 + iVar12);
        pbVar10[1] = 0xc0;
        pbVar11 = pbVar10 + 2;
        param_7 = (byte *)((int)param_7 + -1);
      } while (param_7 != (byte *)0x0);
    }
  }
  return;
}

