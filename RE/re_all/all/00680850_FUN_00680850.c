
void FUN_00680850(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x16a0) != 0) {
    do {
      uVar8 = (uint)*(ushort *)(*(int *)(param_1 + 0x16a4) + uVar3 * 2);
      uVar10 = (uint)*(byte *)(uVar3 + *(int *)(param_1 + 0x1698));
      uVar3 = uVar3 + 1;
      if (uVar8 == 0) {
        uVar8 = (uint)*(ushort *)(param_2 + 2 + uVar10 * 4);
        iVar4 = *(int *)(param_1 + 0x16bc);
        if ((int)(0x10 - uVar8) < iVar4) {
          uVar1 = *(ushort *)(param_2 + uVar10 * 4);
          *(ushort *)(param_1 + 0x16b8) =
               *(ushort *)(param_1 + 0x16b8) | uVar1 << ((byte)iVar4 & 0x1f);
          *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
               *(undefined1 *)(param_1 + 0x16b8);
          iVar5 = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x14) = iVar5;
          *(undefined1 *)(iVar5 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          iVar4 = *(int *)(param_1 + 0x16bc) + -0x10 + uVar8;
          *(ushort *)(param_1 + 0x16b8) = uVar1 >> (0x10U - (char)*(int *)(param_1 + 0x16bc) & 0x1f)
          ;
        }
        else {
          *(ushort *)(param_1 + 0x16b8) =
               *(ushort *)(param_1 + 0x16b8) |
               *(short *)(param_2 + uVar10 * 4) << ((byte)iVar4 & 0x1f);
          iVar4 = iVar4 + uVar8;
        }
LAB_00680bc7:
        *(int *)(param_1 + 0x16bc) = iVar4;
      }
      else {
        uVar7 = (uint)(byte)(&DAT_00822464)[uVar10];
        uVar9 = (uint)*(ushort *)(param_2 + 0x406 + uVar7 * 4);
        bVar2 = (byte)*(int *)(param_1 + 0x16bc);
        if ((int)(0x10 - uVar9) < *(int *)(param_1 + 0x16bc)) {
          uVar1 = *(ushort *)(param_2 + 0x404 + uVar7 * 4);
          *(ushort *)(param_1 + 0x16b8) = *(ushort *)(param_1 + 0x16b8) | uVar1 << (bVar2 & 0x1f);
          *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
               *(undefined1 *)(param_1 + 0x16b8);
          iVar5 = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x14) = iVar5;
          *(undefined1 *)(*(int *)(param_1 + 8) + iVar5) = *(undefined1 *)(param_1 + 0x16b9);
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          *(ushort *)(param_1 + 0x16b8) = uVar1 >> (0x10U - (char)*(int *)(param_1 + 0x16bc) & 0x1f)
          ;
          *(uint *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + -0x10 + uVar9;
        }
        else {
          *(ushort *)(param_1 + 0x16b8) =
               *(ushort *)(param_1 + 0x16b8) |
               *(short *)(param_2 + 0x404 + uVar7 * 4) << (bVar2 & 0x1f);
          *(uint *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + uVar9;
        }
        iVar5 = *(int *)(&DAT_00821c20 + uVar7 * 4);
        if (iVar5 != 0) {
          iVar6 = uVar10 - *(int *)(&DAT_00822564 + uVar7 * 4);
          iVar4 = *(int *)(param_1 + 0x16bc);
          if (0x10 - iVar5 < iVar4) {
            *(ushort *)(param_1 + 0x16b8) =
                 *(ushort *)(param_1 + 0x16b8) | (ushort)(iVar6 << ((byte)iVar4 & 0x1f));
            *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
                 *(undefined1 *)(param_1 + 0x16b8);
            iVar4 = *(int *)(param_1 + 0x14) + 1;
            *(int *)(param_1 + 0x14) = iVar4;
            *(undefined1 *)(*(int *)(param_1 + 8) + iVar4) = *(undefined1 *)(param_1 + 0x16b9);
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
            *(ushort *)(param_1 + 0x16b8) =
                 (ushort)iVar6 >> (0x10U - (char)*(int *)(param_1 + 0x16bc) & 0x1f);
            *(int *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + -0x10 + iVar5;
          }
          else {
            *(ushort *)(param_1 + 0x16b8) =
                 *(ushort *)(param_1 + 0x16b8) | (ushort)(iVar6 << ((byte)iVar4 & 0x1f));
            *(int *)(param_1 + 0x16bc) = iVar4 + iVar5;
          }
        }
        uVar10 = uVar8 - 1;
        if (uVar10 < 0x100) {
          bVar2 = (&DAT_00822263)[uVar8];
        }
        else {
          bVar2 = (&DAT_00822364)[uVar10 >> 7];
        }
        uVar8 = (uint)bVar2;
        iVar5 = *(int *)(param_1 + 0x16bc);
        uVar7 = (uint)*(ushort *)(param_3 + 2 + uVar8 * 4);
        if ((int)(0x10 - uVar7) < iVar5) {
          uVar1 = *(ushort *)(param_3 + uVar8 * 4);
          *(ushort *)(param_1 + 0x16b8) =
               *(ushort *)(param_1 + 0x16b8) | uVar1 << ((byte)iVar5 & 0x1f);
          *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
               *(undefined1 *)(param_1 + 0x16b8);
          iVar5 = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x14) = iVar5;
          *(undefined1 *)(*(int *)(param_1 + 8) + iVar5) = *(undefined1 *)(param_1 + 0x16b9);
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          *(ushort *)(param_1 + 0x16b8) = uVar1 >> (0x10U - (char)*(int *)(param_1 + 0x16bc) & 0x1f)
          ;
          *(uint *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + -0x10 + uVar7;
        }
        else {
          *(ushort *)(param_1 + 0x16b8) =
               *(ushort *)(param_1 + 0x16b8) |
               *(short *)(param_3 + uVar8 * 4) << ((byte)iVar5 & 0x1f);
          *(uint *)(param_1 + 0x16bc) = iVar5 + uVar7;
        }
        iVar5 = *(int *)(&DAT_00821c94 + uVar8 * 4);
        if (iVar5 != 0) {
          iVar6 = uVar10 - *(int *)(&DAT_008225d8 + uVar8 * 4);
          iVar4 = *(int *)(param_1 + 0x16bc);
          if (iVar4 <= 0x10 - iVar5) {
            *(ushort *)(param_1 + 0x16b8) =
                 *(ushort *)(param_1 + 0x16b8) | (ushort)(iVar6 << ((byte)iVar4 & 0x1f));
            iVar4 = iVar4 + iVar5;
            goto LAB_00680bc7;
          }
          *(ushort *)(param_1 + 0x16b8) =
               *(ushort *)(param_1 + 0x16b8) | (ushort)(iVar6 << ((byte)iVar4 & 0x1f));
          *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
               *(undefined1 *)(param_1 + 0x16b8);
          iVar4 = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x14) = iVar4;
          *(undefined1 *)(iVar4 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
          iVar4 = *(int *)(param_1 + 0x16bc);
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          *(int *)(param_1 + 0x16bc) = iVar4 + -0x10 + iVar5;
          *(ushort *)(param_1 + 0x16b8) = (ushort)iVar6 >> (0x10U - (char)iVar4 & 0x1f);
        }
      }
    } while (uVar3 < *(uint *)(param_1 + 0x16a0));
  }
  iVar5 = *(int *)(param_1 + 0x16bc);
  uVar3 = (uint)*(ushort *)(param_2 + 0x402);
  if ((int)(0x10 - uVar3) < iVar5) {
    uVar1 = *(ushort *)(param_2 + 0x400);
    *(ushort *)(param_1 + 0x16b8) = *(ushort *)(param_1 + 0x16b8) | uVar1 << ((byte)iVar5 & 0x1f);
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16b8);
    iVar5 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar5;
    *(undefined1 *)(iVar5 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(ushort *)(param_1 + 0x16b8) = uVar1 >> (0x10U - (char)*(int *)(param_1 + 0x16bc) & 0x1f);
    *(uint *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + -0x10 + uVar3;
    return;
  }
  *(ushort *)(param_1 + 0x16b8) =
       *(ushort *)(param_1 + 0x16b8) | *(short *)(param_2 + 0x400) << ((byte)iVar5 & 0x1f);
  *(uint *)(param_1 + 0x16bc) = iVar5 + uVar3;
  return;
}

