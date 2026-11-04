
undefined4
FUN_0065c6a0(int param_1,int *param_2,int param_3,undefined4 param_4,uint param_5,
            undefined4 *param_6)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (param_3 == 0) {
    *param_2 = *param_2 + 1;
    return 1;
  }
  if ((*(uint *)(param_1 + 0xc) & 0x80000) != 0) {
    uVar1 = FUN_0065d350(param_1,param_2,param_3,param_4,param_5,param_6);
    return uVar1;
  }
  puVar2 = (undefined4 *)FUN_006507d0(param_5 * 4);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFWriteDirectoryTagIfdIfd8Array",
                 s_Out_of_memory_00a066e4);
    return 0;
  }
  uVar3 = 0;
  puVar4 = puVar2;
  if (param_5 != 0) {
    do {
      if (param_6[1] != 0) {
        FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFWriteDirectoryTagIfdIfd8Array",
                     s_Attempt_to_write_value_larger_th_00a0a714);
        FUN_006507e0(puVar2);
        return 0;
      }
      uVar1 = *param_6;
      param_6 = param_6 + 2;
      *puVar4 = uVar1;
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 < param_5);
  }
  uVar1 = FUN_0065d300(param_1,param_2,param_3,param_4,param_5,puVar2);
  FUN_006507e0(puVar2);
  return uVar1;
}

