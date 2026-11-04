
void FUN_006802d0(int param_1,int param_2,ushort *param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint local_8;
  int local_4;
  
  local_8 = 0xffffffff;
  iVar2 = 7;
  iVar6 = 4;
  if (*(ushort *)(param_2 + 2) == 0) {
    iVar2 = 0x8a;
    iVar6 = 3;
  }
  if (-1 < (int)param_3) {
    local_4 = (int)param_3 + 1;
    iVar3 = 0;
    uVar4 = (uint)*(ushort *)(param_2 + 2);
    param_3 = (ushort *)(param_2 + 6);
    do {
      param_2 = iVar3 + 1;
      uVar5 = (uint)*param_3;
      if ((iVar2 <= param_2) || (uVar4 != uVar5)) {
        if (param_2 < iVar6) {
          do {
            iVar2 = *(int *)(param_1 + 0x16bc);
            uVar7 = (uint)*(ushort *)(param_1 + 0xa7e + uVar4 * 4);
            if ((int)(0x10 - uVar7) < iVar2) {
              uVar1 = *(ushort *)(param_1 + 0xa7c + uVar4 * 4);
              *(ushort *)(param_1 + 0x16b8) =
                   *(ushort *)(param_1 + 0x16b8) | uVar1 << ((byte)iVar2 & 0x1f);
              *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                   *(undefined1 *)(param_1 + 0x16b8);
              iVar2 = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x14) = iVar2;
              *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              *(ushort *)(param_1 + 0x16b8) =
                   uVar1 >> (0x10U - (char)*(int *)(param_1 + 0x16bc) & 0x1f);
              *(uint *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + -0x10 + uVar7;
            }
            else {
              *(ushort *)(param_1 + 0x16b8) =
                   *(ushort *)(param_1 + 0x16b8) |
                   *(short *)(param_1 + 0xa7c + uVar4 * 4) << ((byte)iVar2 & 0x1f);
              *(uint *)(param_1 + 0x16bc) = iVar2 + uVar7;
            }
            param_2 = param_2 + -1;
          } while (param_2 != 0);
        }
        else if (uVar4 == 0) {
          if (param_2 < 0xb) {
            iVar2 = *(int *)(param_1 + 0x16bc);
            uVar7 = (uint)*(ushort *)(param_1 + 0xac2);
            if ((int)(0x10 - uVar7) < iVar2) {
              uVar1 = *(ushort *)(param_1 + 0xac0);
              *(ushort *)(param_1 + 0x16b8) =
                   *(ushort *)(param_1 + 0x16b8) | uVar1 << ((byte)iVar2 & 0x1f);
              *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                   *(undefined1 *)(param_1 + 0x16b8);
              iVar2 = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x14) = iVar2;
              *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              *(ushort *)(param_1 + 0x16b8) =
                   uVar1 >> (0x10U - (char)*(int *)(param_1 + 0x16bc) & 0x1f);
              *(uint *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + -0x10 + uVar7;
            }
            else {
              *(ushort *)(param_1 + 0x16b8) =
                   *(ushort *)(param_1 + 0x16b8) |
                   *(short *)(param_1 + 0xac0) << ((byte)iVar2 & 0x1f);
              *(uint *)(param_1 + 0x16bc) = iVar2 + uVar7;
            }
            iVar2 = *(int *)(param_1 + 0x16bc);
            if (iVar2 < 0xe) {
              *(ushort *)(param_1 + 0x16b8) =
                   *(ushort *)(param_1 + 0x16b8) | (ushort)(iVar3 + -2 << ((byte)iVar2 & 0x1f));
              iVar2 = iVar2 + 3;
LAB_006807e9:
              *(int *)(param_1 + 0x16bc) = iVar2;
            }
            else {
              *(ushort *)(param_1 + 0x16b8) =
                   *(ushort *)(param_1 + 0x16b8) | (ushort)(iVar3 + -2 << ((byte)iVar2 & 0x1f));
              *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                   *(undefined1 *)(param_1 + 0x16b8);
              iVar2 = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x14) = iVar2;
              *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
              iVar2 = *(int *)(param_1 + 0x16bc);
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x16bc) = iVar2 + -0xd;
              *(ushort *)(param_1 + 0x16b8) = (ushort)(iVar3 + -2) >> (0x10U - (char)iVar2 & 0x1f);
            }
          }
          else {
            iVar2 = *(int *)(param_1 + 0x16bc);
            uVar7 = (uint)*(ushort *)(param_1 + 0xac6);
            if ((int)(0x10 - uVar7) < iVar2) {
              uVar1 = *(ushort *)(param_1 + 0xac4);
              *(ushort *)(param_1 + 0x16b8) =
                   *(ushort *)(param_1 + 0x16b8) | uVar1 << ((byte)iVar2 & 0x1f);
              *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                   *(undefined1 *)(param_1 + 0x16b8);
              iVar2 = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x14) = iVar2;
              *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              *(ushort *)(param_1 + 0x16b8) =
                   uVar1 >> (0x10U - (char)*(int *)(param_1 + 0x16bc) & 0x1f);
              *(uint *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + -0x10 + uVar7;
            }
            else {
              *(ushort *)(param_1 + 0x16b8) =
                   *(ushort *)(param_1 + 0x16b8) |
                   *(short *)(param_1 + 0xac4) << ((byte)iVar2 & 0x1f);
              *(uint *)(param_1 + 0x16bc) = iVar2 + uVar7;
            }
            iVar2 = *(int *)(param_1 + 0x16bc);
            if (iVar2 < 10) {
              *(ushort *)(param_1 + 0x16b8) =
                   *(ushort *)(param_1 + 0x16b8) | (ushort)(iVar3 + -10 << ((byte)iVar2 & 0x1f));
              iVar2 = iVar2 + 7;
              goto LAB_006807e9;
            }
            *(ushort *)(param_1 + 0x16b8) =
                 *(ushort *)(param_1 + 0x16b8) | (ushort)(iVar3 + -10 << ((byte)iVar2 & 0x1f));
            *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                 *(undefined1 *)(param_1 + 0x16b8);
            iVar2 = *(int *)(param_1 + 0x14) + 1;
            *(int *)(param_1 + 0x14) = iVar2;
            *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
            iVar2 = *(int *)(param_1 + 0x16bc);
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
            *(int *)(param_1 + 0x16bc) = iVar2 + -9;
            *(ushort *)(param_1 + 0x16b8) = (ushort)(iVar3 + -10) >> (0x10U - (char)iVar2 & 0x1f);
          }
        }
        else {
          if (uVar4 != local_8) {
            iVar2 = *(int *)(param_1 + 0x16bc);
            uVar7 = (uint)*(ushort *)(param_1 + 0xa7e + uVar4 * 4);
            if ((int)(0x10 - uVar7) < iVar2) {
              uVar1 = *(ushort *)(param_1 + 0xa7c + uVar4 * 4);
              *(ushort *)(param_1 + 0x16b8) =
                   *(ushort *)(param_1 + 0x16b8) | uVar1 << ((byte)iVar2 & 0x1f);
              *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                   *(undefined1 *)(param_1 + 0x16b8);
              iVar2 = *(int *)(param_1 + 0x14) + 1;
              *(int *)(param_1 + 0x14) = iVar2;
              *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
              *(ushort *)(param_1 + 0x16b8) =
                   uVar1 >> (0x10U - (char)*(int *)(param_1 + 0x16bc) & 0x1f);
              *(uint *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + -0x10 + uVar7;
            }
            else {
              *(ushort *)(param_1 + 0x16b8) =
                   *(ushort *)(param_1 + 0x16b8) |
                   *(short *)(param_1 + 0xa7c + uVar4 * 4) << ((byte)iVar2 & 0x1f);
              *(uint *)(param_1 + 0x16bc) = iVar2 + uVar7;
            }
            param_2 = iVar3;
          }
          iVar2 = *(int *)(param_1 + 0x16bc);
          uVar7 = (uint)*(ushort *)(param_1 + 0xabe);
          if ((int)(0x10 - uVar7) < iVar2) {
            uVar1 = *(ushort *)(param_1 + 0xabc);
            *(ushort *)(param_1 + 0x16b8) =
                 *(ushort *)(param_1 + 0x16b8) | uVar1 << ((byte)iVar2 & 0x1f);
            *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
                 *(undefined1 *)(param_1 + 0x16b8);
            iVar2 = *(int *)(param_1 + 0x14) + 1;
            *(int *)(param_1 + 0x14) = iVar2;
            *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
            *(ushort *)(param_1 + 0x16b8) =
                 uVar1 >> (0x10U - (char)*(int *)(param_1 + 0x16bc) & 0x1f);
            *(uint *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + -0x10 + uVar7;
          }
          else {
            *(ushort *)(param_1 + 0x16b8) =
                 *(ushort *)(param_1 + 0x16b8) | *(short *)(param_1 + 0xabc) << ((byte)iVar2 & 0x1f)
            ;
            *(uint *)(param_1 + 0x16bc) = iVar2 + uVar7;
          }
          iVar2 = *(int *)(param_1 + 0x16bc);
          if (iVar2 < 0xf) {
            *(ushort *)(param_1 + 0x16b8) =
                 *(ushort *)(param_1 + 0x16b8) | (ushort)(param_2 + -3 << ((byte)iVar2 & 0x1f));
            iVar2 = iVar2 + 2;
            goto LAB_006807e9;
          }
          *(ushort *)(param_1 + 0x16b8) =
               *(ushort *)(param_1 + 0x16b8) | (ushort)(param_2 + -3 << ((byte)iVar2 & 0x1f));
          *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
               *(undefined1 *)(param_1 + 0x16b8);
          iVar2 = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x14) = iVar2;
          *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
          iVar2 = *(int *)(param_1 + 0x16bc);
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x16bc) = iVar2 + -0xe;
          *(ushort *)(param_1 + 0x16b8) = (ushort)(param_2 + -3) >> (0x10U - (char)iVar2 & 0x1f);
        }
        param_2 = 0;
        local_8 = uVar4;
        if (uVar5 == 0) {
          iVar2 = 0x8a;
          iVar6 = 3;
        }
        else if (uVar4 == uVar5) {
          iVar2 = 6;
          iVar6 = 3;
        }
        else {
          iVar2 = 7;
          iVar6 = 4;
        }
      }
      param_3 = param_3 + 2;
      local_4 = local_4 + -1;
      iVar3 = param_2;
      uVar4 = uVar5;
    } while (local_4 != 0);
  }
  return;
}

