
undefined4 FUN_0057c150(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  undefined **ppuVar6;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [2];
  ushort uStack_1a;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined2 uStack_14;
  undefined2 uStack_12;
  undefined2 uStack_10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined2 uStack_8;
  undefined2 uStack_6;
  
  local_20 = 1;
  if (DAT_00ca3cd8 == 0) {
    return 0xffffffff;
  }
  FUN_0056da60(&DAT_00cc6284,"..\\..\\..\\..\\Source\\Library\\Main\\DxNetwork.cpp",0x5b5);
  FUN_0057bf50(0);
  if ((((DAT_00cc6240 != 0) && (-1 < (int)DAT_00ca3cd4)) &&
      ((DAT_00ca3cd4 & 0x7c000000) == DAT_00cc6268)) &&
     ((((int)(DAT_00ca3cd4 & 0xffff) < DAT_00cc6270 &&
       (piVar1 = *(int **)(DAT_00cc6244 + (DAT_00ca3cd4 & 0xffff) * 4), piVar1 != (int *)0x0)) &&
      ((*piVar1 * 0x10000 == (DAT_00ca3cd4 & 0x3ff0000) && (piVar1[4] == 0)))))) {
    uVar3 = FUN_005809a0(10,0,0xffffffff);
    if (((DAT_00cc6240 != 0) && (-1 < (int)uVar3)) &&
       (((uVar3 & 0x7c000000) == DAT_00cc6268 &&
        ((((int)(uVar3 & 0xffff) < DAT_00cc6270 &&
          (piVar2 = *(int **)(DAT_00cc6244 + (uVar3 & 0xffff) * 4), piVar2 != (int *)0x0)) &&
         (*piVar2 * 0x10000 == (uVar3 & 0x3ff0000))))))) {
      piVar2[0xc] = 0;
      piVar2[0xd] = 0;
      piVar2[0xf] = piVar1[0xf];
      piVar2[0x10] = 0;
      piVar2[0xe] = 1;
      piVar2[0x11] = 0;
      piVar2[0x12] = 1;
      piVar2[0x13] = 0;
      piVar2[0x14] = 0;
      piVar2[0x15] = 1;
      bVar5 = DAT_00ca3cf0 == 0;
      piVar2[0x16] = (uint)bVar5;
      piVar2[0x17] = (uint)(DAT_00ca3cf4 == 0);
      if (bVar5 == 1) {
        FUN_00597380(piVar2 + 0x1a);
        piVar2[0x19] = 0;
        piVar2[0x1f] = 0;
        piVar2[0x20] = 0;
        FUN_00597380(piVar2 + 0x21);
        piVar2[0x26] = 0;
        piVar2[0x27] = 0;
      }
      if (piVar2[0xf] == 0) {
        local_24 = 0x10;
        iVar4 = (*DAT_00aba108)(piVar1[0x18],local_1c,&local_24);
        piVar2[0x18] = iVar4;
        if (iVar4 != -1) {
          *(undefined1 *)(piVar2 + 0x28) = uStack_18;
          *(undefined1 *)((int)piVar2 + 0xa1) = uStack_17;
          *(undefined1 *)((int)piVar2 + 0xa2) = uStack_16;
          *(undefined1 *)((int)piVar2 + 0xa3) = uStack_15;
          piVar2[0x2d] = (uint)uStack_1a;
          goto LAB_0057c3d7;
        }
      }
      else {
        local_24 = 0x1c;
        iVar4 = (*DAT_00aba108)(piVar1[0x18],local_1c);
        piVar2[0x18] = iVar4;
        if (iVar4 != -1) {
          *(undefined2 *)(piVar2 + 0x29) = uStack_14;
          *(undefined2 *)((int)piVar2 + 0xa6) = uStack_12;
          *(undefined2 *)(piVar2 + 0x2a) = uStack_10;
          *(undefined2 *)((int)piVar2 + 0xaa) = uStack_e;
          *(undefined2 *)(piVar2 + 0x2b) = uStack_c;
          *(undefined2 *)((int)piVar2 + 0xae) = uStack_a;
          *(undefined2 *)(piVar2 + 0x2c) = uStack_8;
          *(undefined2 *)((int)piVar2 + 0xb2) = uStack_6;
          piVar2[0x2d] = (uint)uStack_1a;
LAB_0057c3d7:
          iVar4 = (*DAT_00aba0d8)(piVar2[0x18],DAT_00ca3cec,0x505,0x23);
          if (iVar4 != -1) goto LAB_0057c433;
          ppuVar6 = (undefined **)&DAT_007d8338;
          goto LAB_0057c3f8;
        }
      }
      ppuVar6 = &PTR_LAB_007d8380;
LAB_0057c3f8:
      FUN_0057bed0(ppuVar6);
      FUN_00580b80(uVar3);
      FUN_0056dac0(&DAT_00cc6284);
      return 0xffffffff;
    }
    FUN_0056bb10(&PTR_LAB_007d8304);
  }
  local_20 = 0xffffffff;
LAB_0057c433:
  FUN_0056dac0(&DAT_00cc6284);
  return local_20;
}

