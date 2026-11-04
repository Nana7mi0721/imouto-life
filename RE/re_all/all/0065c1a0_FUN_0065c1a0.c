
undefined4 FUN_0065c1a0(int param_1,int *param_2,int param_3,undefined4 param_4,undefined2 param_5)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  ushort uVar4;
  
  if (param_3 == 0) {
    *param_2 = *param_2 + 1;
    return 1;
  }
  puVar1 = (undefined2 *)FUN_006507d0((uint)*(ushort *)(param_1 + 0x62) << 1);
  if (puVar1 == (undefined2 *)0x0) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFWriteDirectoryTagShortPerSample",
                 s_Out_of_memory_00a066e4);
    return 0;
  }
  uVar4 = 0;
  puVar2 = puVar1;
  if (*(short *)(param_1 + 0x62) != 0) {
    do {
      *puVar2 = param_5;
      uVar4 = uVar4 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar4 < *(ushort *)(param_1 + 0x62));
  }
  uVar3 = FUN_0065cc60(param_1,param_2,param_3,param_4,*(undefined2 *)(param_1 + 0x62),puVar1);
  FUN_006507e0(puVar1);
  return uVar3;
}

