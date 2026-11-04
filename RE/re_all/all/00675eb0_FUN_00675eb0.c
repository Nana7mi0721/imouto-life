
void FUN_00675eb0(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 4;
  do {
    uVar1 = param_2 & 0xff;
    if (((uVar1 < 0x41) || (0x7a < uVar1)) || ((0x5a < uVar1 && (uVar1 < 0x61)))) {
      FUN_00668a30(param_1,s_invalid_chunk_type_00a0d1a4);
    }
    param_2 = param_2 >> 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

