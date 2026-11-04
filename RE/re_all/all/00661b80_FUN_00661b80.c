
void FUN_00661b80(undefined4 param_1,int param_2,undefined4 param_3,uint param_4,uint param_5)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  uVar1 = *(uint *)(param_2 + 0xc) & 0x400;
  if (uVar1 == 0) {
    uVar4 = *(undefined4 *)(param_2 + 0x1c4);
  }
  else {
    uVar4 = *(undefined4 *)(param_2 + 0x1ec);
  }
  pcVar3 = &DAT_00a09b78;
  if (uVar1 == 0) {
    pcVar3 = s_strip_00a09b70;
  }
  pcVar2 = s_Premature_EOL_00a0b410;
  if (param_5 <= param_4) {
    pcVar2 = s_Line_length_mismatch_00a0b3f8;
  }
  FUN_00653460(*(undefined4 *)(param_2 + 0x274),param_1,s__s_at_line__u_of__s__u__got__u__e_00a0b3c8
               ,pcVar2,param_3,pcVar3,uVar4,param_4,param_5);
  return;
}

