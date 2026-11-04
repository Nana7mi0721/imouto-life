
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_0079c620(int param_1,int *param_2,short *param_3,int param_4)

{
  ushort uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  undefined1 *puVar8;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  short *psVar12;
  int iVar13;
  uint uVar14;
  undefined4 *puVar15;
  int *piVar16;
  uint auStackY_264 [128];
  short local_4c;
  short local_4a;
  short local_48;
  short local_46;
  short local_44;
  short local_42;
  short local_40;
  short local_3e;
  short local_3c;
  short local_3a;
  short local_38;
  short local_36;
  short local_34;
  short local_32;
  short local_30;
  short local_2e;
  int local_20;
  short *local_1c;
  int local_18 [4];
  int *local_8;
  
  piVar16 = (int *)(param_1 + 0xad4);
  if (*(int *)(param_1 + 0x90c) != *(int *)(param_1 + 0x103c)) {
    FUN_0079c5b0();
    *(undefined4 *)(param_1 + 0x103c) = *(undefined4 *)(param_1 + 0x90c);
  }
  if (*(int *)(param_1 + 0x1040) == 0) {
    if (*(int *)(param_1 + 0x1044) == 0) {
      local_18[3] = 0;
      if (0 < *(int *)(param_1 + 0x924)) {
        local_8 = (int *)(param_1 + 0x928);
        psVar12 = (short *)(param_1 + 0xfd4);
        do {
          uVar5 = (int)(short)*local_8 - (int)*psVar12;
          local_18[3] = local_18[3] + 1;
          *psVar12 = *psVar12 + (short)((uVar5 & 0xffff) * 0x3fdc >> 0x10) +
                     (short)(uVar5 >> 0x10) * 0x3fdc;
          local_8 = (int *)((int)local_8 + 2);
          psVar12 = psVar12 + 1;
        } while (local_18[3] < *(int *)(param_1 + 0x924));
      }
      iVar6 = *(int *)(param_1 + 0x914);
      iVar13 = 0;
      iVar9 = 0;
      iVar3 = 0;
      if (0 < iVar6) {
        local_8 = (int *)((int)param_2 + 0x10);
        do {
          if (iVar13 < *local_8) {
            iVar9 = iVar3;
            iVar13 = *local_8;
          }
          iVar3 = iVar3 + 1;
          local_8 = local_8 + 1;
        } while (iVar3 < iVar6);
      }
      piVar16 = (int *)(param_1 + 0xad4);
      local_8 = piVar16;
      _memmove(piVar16 + *(int *)(param_1 + 0x91c),piVar16,
               (iVar6 + -1) * *(int *)(param_1 + 0x91c) * 4);
      iVar6 = *(int *)(param_1 + 0x91c);
      piVar10 = (int *)(param_1 + 4 + iVar6 * iVar9 * 4);
      for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar16 = *piVar10;
        piVar10 = piVar10 + 1;
        piVar16 = piVar16 + 1;
      }
      iVar6 = 0;
      if (0 < *(int *)(param_1 + 0x914)) {
        param_2 = (int *)((int)param_2 + 0x10);
        do {
          uVar5 = *param_2 - local_8[0x158];
          iVar6 = iVar6 + 1;
          local_8[0x158] =
               local_8[0x158] + ((int)((uVar5 & 0xffff) * 0x121a) >> 0x10) +
               ((int)uVar5 >> 0x10) * 0x121a;
          param_2 = param_2 + 1;
        } while (iVar6 < *(int *)(param_1 + 0x914));
      }
      piVar16 = local_8;
    }
    if (*(int *)(param_1 + 0x1040) == 0) {
      piVar16 = piVar16 + 0x148;
      for (uVar5 = *(uint *)(param_1 + 0x924) & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *piVar16 = 0;
        piVar16 = piVar16 + 1;
      }
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined1 *)piVar16 = 0;
        piVar16 = (int *)((int)piVar16 + 1);
      }
      return;
    }
  }
  iVar6 = -(param_4 * 4 + 0x40);
  puVar8 = (undefined1 *)((int)auStackY_264 + iVar6 + 0x20c);
  uVar1 = *(ushort *)(param_1 + 0x1080);
  uVar5 = ((*(int *)(param_1 + 0x1094) >> 0xf) + 1 >> 1) * (int)(short)uVar1 +
          ((int)((uint)uVar1 * (int)*(short *)(param_1 + 0x1094)) >> 0x10) +
          ((int)(short)uVar1 >> 0x10) * (int)*(short *)(param_1 + 0x1094);
  uVar14 = (int)uVar5 >> 0xb;
  if (((int)uVar5 < 0x200000) && (uVar4 = piVar16[0x158], (int)uVar4 < 0x800001)) {
    local_20 = (int)(short)uVar4;
    uVar5 = ((((((int)uVar4 >> 0xf) + 1 >> 1) * uVar4 -
              ((int)((uVar5 & 0xffff) * (int)(short)uVar5) >> 0xb & 0xffffffe0U)) -
             ((uVar14 & 0xfffffff0) + 0x10 & 0xffffffe0) * uVar5) -
            (uVar14 & 0xffffffe0) * (int)(short)uVar5) +
            ((int)((uVar4 & 0xffff) * local_20) >> 0x10) + ((int)uVar4 >> 0x10) * local_20;
    if ((int)uVar5 < 1) {
      iVar9 = 0;
    }
    else {
      *(uint *)((int)auStackY_264 + iVar6 + 0x208) = uVar5;
      *(undefined4 *)((int)auStackY_264 + iVar6 + 0x204) = 0x79c8cd;
      iVar9 = FUN_007a22e0();
      uVar14 = 0x20 - iVar9;
      puVar8 = (undefined1 *)((int)auStackY_264 + iVar6 + 0x20c);
      iVar9 = 0x18 - uVar14;
      bVar2 = (byte)iVar9;
      if (iVar9 != 0) {
        if (iVar9 < 0) {
          uVar4 = uVar5 >> (bVar2 + 0x20 & 0x1f);
          uVar5 = uVar5 << (-bVar2 & 0x1f);
        }
        else {
          uVar4 = uVar5 << (0x20 - bVar2 & 0x1f);
          uVar5 = uVar5 >> (bVar2 & 0x1f);
        }
        uVar5 = uVar4 | uVar5;
      }
      uVar14 = (int)((-(uint)((uVar14 & 1) != 0) & 0xffffcb7a) + 0xb486) >>
               ((byte)((int)uVar14 >> 1) & 0x1f);
      iVar9 = (int)(short)(((ushort)uVar5 & 0x7f) * 0xd5);
      iVar9 = (((int)uVar14 >> 0x10) * iVar9 + uVar14 + ((int)((uVar14 & 0xffff) * iVar9) >> 0x10))
              * 0x100;
    }
  }
  else {
    uVar5 = (piVar16[0x158] >> 0x10) * (piVar16[0x158] >> 0x10) -
            (uVar14 & 0xffffffe0) * ((int)uVar5 >> 0x10);
    if ((int)uVar5 < 1) {
      iVar9 = 0;
      puVar8 = (undefined1 *)((int)auStackY_264 + iVar6 + 0x20c);
    }
    else {
      *(uint *)((int)auStackY_264 + iVar6 + 0x208) = uVar5;
      *(undefined4 *)((int)auStackY_264 + iVar6 + 0x204) = 0x79c98b;
      iVar9 = FUN_007a22e0();
      uVar14 = 0x20 - iVar9;
      puVar8 = (undefined1 *)((int)auStackY_264 + iVar6 + 0x20c);
      iVar9 = 0x18 - uVar14;
      local_20 = -iVar9;
      if (iVar9 != 0) {
        bVar2 = (byte)iVar9;
        if (iVar9 < 0) {
          uVar4 = uVar5 >> (bVar2 + 0x20 & 0x1f);
          uVar5 = uVar5 << ((byte)local_20 & 0x1f);
        }
        else {
          uVar4 = uVar5 << (0x20 - bVar2 & 0x1f);
          uVar5 = uVar5 >> (bVar2 & 0x1f);
        }
        uVar5 = uVar4 | uVar5;
      }
      uVar14 = (int)((-(uint)((uVar14 & 1) != 0) & 0xffffcb7a) + 0xb486) >>
               ((byte)((int)uVar14 >> 1) & 0x1f);
      iVar9 = (int)(short)(((ushort)uVar5 & 0x7f) * 0xd5);
      iVar9 = ((int)uVar14 >> 0x10) * iVar9 + uVar14 + ((int)((uVar14 & 0xffff) * iVar9) >> 0x10);
    }
    iVar9 = iVar9 << 0x10;
  }
  uVar5 = 0xff;
  local_18[3] = 0xff;
  if (param_4 < 0xff) {
    do {
      uVar5 = (int)uVar5 >> 1;
    } while (param_4 < (int)uVar5);
    local_18[3] = uVar5;
  }
  iVar13 = *(int *)(param_1 + 0x1038);
  if (0 < param_4) {
    local_18[2] = param_4;
    local_20 = (iVar9 >> 0x13) + 1 >> 1;
    local_8 = (int *)((int)local_18 + iVar6);
    iVar9 = (int)(short)(iVar9 >> 4);
    do {
      iVar13 = iVar13 * 0xbb38435 + 0x3619636b;
      uVar5 = *(uint *)(param_1 + 0xad4 + (iVar13 >> 0x18 & local_18[3]) * 4);
      iVar3 = ((int)((uVar5 & 0xffff) * iVar9) >> 0x10) + ((int)uVar5 >> 0x10) * iVar9 +
              local_20 * uVar5;
      if (iVar3 < 0x8000) {
        if (iVar3 < -0x8000) {
          iVar3 = -0x8000;
        }
      }
      else {
        iVar3 = 0x7fff;
      }
      *local_8 = (int)(short)iVar3;
      local_8 = local_8 + 1;
      local_18[2] = local_18[2] + -1;
    } while (local_18[2] != 0);
  }
  *(int *)(param_1 + 0x1038) = iVar13;
  *(undefined4 *)(puVar8 + -4) = *(undefined4 *)(param_1 + 0x924);
  *(int *)(puVar8 + -8) = param_1 + 0xfd4;
  *(short **)(puVar8 + -0xc) = &local_4c;
  *(undefined4 *)(puVar8 + -0x10) = 0x79caed;
  FUN_0079f570();
  puVar11 = (undefined4 *)(param_1 + 0xff4);
  puVar15 = (undefined4 *)((int)auStackY_264 + iVar6 + 0x20c);
  for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar15 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar15 = puVar15 + 1;
  }
  if (0 < param_4) {
    local_1c = param_3;
    puVar7 = (uint *)((int)local_18 + iVar6 + -0x24);
    local_20 = param_4;
    do {
      iVar9 = ((int)((puVar7[8] & 0xffff) * (int)local_4c) >> 0x10) +
              ((int)((puVar7[7] & 0xffff) * (int)local_4a) >> 0x10) +
              ((int)((puVar7[6] & 0xffff) * (int)local_48) >> 0x10) +
              ((int)((puVar7[5] & 0xffff) * (int)local_46) >> 0x10) +
              ((int)((puVar7[4] & 0xffff) * (int)local_44) >> 0x10) +
              ((int)((puVar7[3] & 0xffff) * (int)local_42) >> 0x10) +
              ((int)((puVar7[2] & 0xffff) * (int)local_40) >> 0x10) +
              ((int)((puVar7[1] & 0xffff) * (int)local_3e) >> 0x10) +
              ((int)((puVar7[-1] & 0xffff) * (int)local_3a) >> 0x10) +
              ((int)((*puVar7 & 0xffff) * (int)local_3c) >> 0x10) +
              ((int)puVar7[8] >> 0x10) * (int)local_4c + ((int)puVar7[7] >> 0x10) * (int)local_4a +
              ((int)puVar7[6] >> 0x10) * (int)local_48 + ((int)puVar7[5] >> 0x10) * (int)local_46 +
              ((int)puVar7[4] >> 0x10) * (int)local_44 + ((int)puVar7[3] >> 0x10) * (int)local_42 +
              ((int)puVar7[2] >> 0x10) * (int)local_40 + ((int)puVar7[1] >> 0x10) * (int)local_3e +
              ((int)puVar7[-1] >> 0x10) * (int)local_3a + ((int)*puVar7 >> 0x10) * (int)local_3c +
              (*(int *)(param_1 + 0x924) >> 1);
      if (*(int *)(param_1 + 0x924) == 0x10) {
        iVar9 = ((int)puVar7[-6] >> 0x10) * (int)local_30 + iVar9 +
                ((int)((puVar7[-7] & 0xffff) * (int)local_2e) >> 0x10) +
                ((int)((puVar7[-2] & 0xffff) * (int)local_38) >> 0x10) +
                ((int)((puVar7[-3] & 0xffff) * (int)local_36) >> 0x10) +
                ((int)((puVar7[-4] & 0xffff) * (int)local_34) >> 0x10) +
                ((int)((puVar7[-5] & 0xffff) * (int)local_32) >> 0x10) +
                ((int)((puVar7[-6] & 0xffff) * (int)local_30) >> 0x10) +
                ((int)puVar7[-7] >> 0x10) * (int)local_2e +
                ((int)puVar7[-2] >> 0x10) * (int)local_38 +
                ((int)puVar7[-3] >> 0x10) * (int)local_36 +
                ((int)puVar7[-4] >> 0x10) * (int)local_34 +
                ((int)puVar7[-5] >> 0x10) * (int)local_32;
      }
      uVar5 = puVar7[9] + iVar9 * 0x10;
      puVar7[9] = uVar5;
      iVar9 = (((int)uVar5 >> 9) + 1 >> 1) + (int)*local_1c;
      if (iVar9 < 0x8000) {
        if (iVar9 < -0x8000) {
          iVar9 = -0x8000;
        }
      }
      else {
        iVar9 = 0x7fff;
      }
      *local_1c = (short)iVar9;
      puVar7 = puVar7 + 1;
      local_1c = local_1c + 1;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  puVar11 = (undefined4 *)((int)auStackY_264 + param_4 * 4 + iVar6 + 0x20c);
  puVar15 = (undefined4 *)(param_1 + 0xff4);
  for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar15 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar15 = puVar15 + 1;
  }
  return;
}

