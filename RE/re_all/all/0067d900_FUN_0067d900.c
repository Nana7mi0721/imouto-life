
void FUN_0067d900(int *param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  
  uVar6 = param_1[0xb];
  while( true ) {
    iVar7 = (param_1[0xf] - param_1[0x1d]) - param_1[0x1b];
    if (param_1[0xb] + -0x106 + uVar6 <= (uint)param_1[0x1b]) {
      puVar8 = (undefined4 *)(param_1[0xe] + uVar6);
      puVar10 = (undefined4 *)param_1[0xe];
      for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      for (uVar4 = uVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      param_1[0x1c] = param_1[0x1c] - uVar6;
      iVar9 = param_1[0x13];
      param_1[0x1b] = param_1[0x1b] - uVar6;
      param_1[0x17] = param_1[0x17] - uVar6;
      puVar5 = (ushort *)(param_1[0x11] + iVar9 * 2);
      do {
        puVar5 = puVar5 + -1;
        if (*puVar5 < uVar6) {
          uVar1 = 0;
        }
        else {
          uVar1 = *puVar5 - (short)uVar6;
        }
        iVar9 = iVar9 + -1;
        *puVar5 = uVar1;
      } while (iVar9 != 0);
      puVar5 = (ushort *)(param_1[0x10] + uVar6 * 2);
      uVar4 = uVar6;
      do {
        puVar5 = puVar5 + -1;
        if (*puVar5 < uVar6) {
          uVar1 = 0;
        }
        else {
          uVar1 = *puVar5 - (short)uVar6;
        }
        uVar4 = uVar4 - 1;
        *puVar5 = uVar1;
      } while (uVar4 != 0);
      iVar7 = iVar7 + uVar6;
    }
    if (*(int *)(*param_1 + 4) == 0) break;
    iVar2 = FUN_0067db00(*param_1,param_1[0x1d] + param_1[0x1b] + param_1[0xe],iVar7);
    iVar7 = param_1[0x1d];
    iVar9 = param_1[0x5ad];
    param_1[0x1d] = iVar7 + iVar2;
    if (2 < (uint)(iVar9 + iVar7 + iVar2)) {
      uVar4 = param_1[0x1b] - iVar9;
      uVar3 = (uint)*(byte *)(param_1[0xe] + uVar4);
      param_1[0x12] = uVar3;
      param_1[0x12] =
           (uVar3 << ((byte)param_1[0x16] & 0x1f) ^ (uint)((byte *)(param_1[0xe] + uVar4))[1]) &
           param_1[0x15];
      do {
        if (iVar9 == 0) break;
        uVar3 = ((uint)*(byte *)(param_1[0xe] + 2 + uVar4) ^
                param_1[0x12] << ((byte)param_1[0x16] & 0x1f)) & param_1[0x15];
        param_1[0x12] = uVar3;
        *(undefined2 *)(param_1[0x10] + (param_1[0xd] & uVar4) * 2) =
             *(undefined2 *)(param_1[0x11] + uVar3 * 2);
        *(short *)(param_1[0x11] + param_1[0x12] * 2) = (short)uVar4;
        uVar4 = uVar4 + 1;
        iVar9 = param_1[0x5ad] + -1;
        param_1[0x5ad] = iVar9;
      } while (2 < (uint)(param_1[0x1d] + iVar9));
    }
    if ((0x105 < (uint)param_1[0x1d]) || (*(int *)(*param_1 + 4) == 0)) break;
  }
  uVar6 = param_1[0x5b0];
  uVar4 = param_1[0xf];
  if (uVar6 < uVar4) {
    uVar3 = param_1[0x1d] + param_1[0x1b];
    if (uVar6 < uVar3) {
      uVar4 = uVar4 - uVar3;
      if (0x102 < uVar4) {
        uVar4 = 0x102;
      }
      puVar8 = (undefined4 *)(param_1[0xe] + uVar3);
      for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
      for (uVar6 = uVar4 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar8 = 0;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      param_1[0x5b0] = uVar4 + uVar3;
      return;
    }
    if (uVar6 < uVar3 + 0x102) {
      uVar3 = (uVar3 - uVar6) + 0x102;
      if (uVar4 - uVar6 < uVar3) {
        uVar3 = uVar4 - uVar6;
      }
      puVar8 = (undefined4 *)(param_1[0xe] + uVar6);
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
      for (uVar6 = uVar3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar8 = 0;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      param_1[0x5b0] = param_1[0x5b0] + uVar3;
    }
  }
  return;
}

