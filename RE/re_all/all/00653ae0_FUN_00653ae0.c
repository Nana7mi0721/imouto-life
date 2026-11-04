
undefined4 FUN_00653ae0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00653cc0(*(undefined2 *)(param_1 + 0x16));
  if (puVar1 == (undefined4 *)0x0) {
    FUN_006512e0(param_1[0x9d],*param_1,s_Compression_scheme__u__s_decodin_00a09b80,
                 *(undefined2 *)(param_1 + 0x16),param_2);
    return 0xffffffff;
  }
  FUN_006512e0(param_1[0x9d],*param_1,s__s__s_decoding_is_not_implemente_00a09bb8,*puVar1,param_2);
  return 0xffffffff;
}

