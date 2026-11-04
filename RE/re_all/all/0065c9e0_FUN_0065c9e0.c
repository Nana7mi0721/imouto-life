
undefined4 FUN_0065c9e0(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  ushort uVar8;
  
  uVar8 = *(ushort *)(param_1 + 0xb8);
  if (uVar8 != 0) {
    if (param_3 == 0) {
      *param_2 = *param_2 + 1;
      return 1;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x1d0);
    uVar2 = *(undefined4 *)(param_1 + 0x1d4);
    if ((*(uint *)(param_1 + 0xc) & 0x80000) == 0) {
      puVar4 = (undefined4 *)FUN_006507d0((uint)uVar8 << 2);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFWriteDirectoryTagSubifd",
                     s_Out_of_memory_00a066e4);
        return 0;
      }
      puVar7 = *(undefined4 **)(param_1 + 0xbc);
      uVar8 = 0;
      puVar5 = puVar4;
      if (*(short *)(param_1 + 0xb8) != 0) {
        do {
          uVar3 = *puVar7;
          puVar7 = puVar7 + 2;
          *puVar5 = uVar3;
          uVar8 = uVar8 + 1;
          puVar5 = puVar5 + 1;
        } while (uVar8 < *(ushort *)(param_1 + 0xb8));
      }
      iVar6 = FUN_0065d300(param_1,param_2,param_3,0x14a,*(undefined2 *)(param_1 + 0xb8),puVar4);
      FUN_006507e0(puVar4);
    }
    else {
      iVar6 = FUN_0065d350(param_1,param_2,param_3,0x14a,uVar8,*(undefined4 *)(param_1 + 0xbc));
    }
    if (iVar6 == 0) {
      return 0;
    }
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x2000;
    *(short *)(param_1 + 0x1d8) = *(short *)(param_1 + 0xb8);
    if (*(short *)(param_1 + 0xb8) == 1) {
      *(undefined4 *)(param_1 + 0x1e0) = 0;
      *(undefined4 *)(param_1 + 0x1e4) = 0;
      return 1;
    }
    *(undefined4 *)(param_1 + 0x1e0) = uVar1;
    *(undefined4 *)(param_1 + 0x1e4) = uVar2;
  }
  return 1;
}

