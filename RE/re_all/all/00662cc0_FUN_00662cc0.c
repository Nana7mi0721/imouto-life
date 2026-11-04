
void FUN_00662cc0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = *(uint *)(param_2 + 0xc) & 0x400;
  if (uVar2 == 0) {
    uVar1 = *(undefined4 *)(param_2 + 0x1c4);
  }
  else {
    uVar1 = *(undefined4 *)(param_2 + 0x1ec);
  }
  pcVar3 = &DAT_00a09b78;
  if (uVar2 == 0) {
    pcVar3 = s_strip_00a09b70;
  }
  FUN_006512e0(*(undefined4 *)(param_2 + 0x274),param_1,s_Uncompressed_data__not_supported_00a0b4f4,
               param_3,pcVar3,uVar1,param_4);
  return;
}

