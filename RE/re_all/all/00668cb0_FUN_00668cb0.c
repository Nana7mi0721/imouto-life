
void FUN_00668cb0(int param_1)

{
  int iVar1;
  undefined1 local_48 [64];
  int local_8;
  
  if (param_1 != 0) {
    local_8 = *(int *)(param_1 + 0x44);
    if ((((local_8 != 0) && (*(int *)(param_1 + 0x48) != 0)) && (local_8 != param_1)) &&
       (iVar1 = __setjmp3(local_48,0), iVar1 == 0)) {
      *(undefined1 **)(param_1 + 0x44) = local_48;
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined1 **)(param_1 + 0x40) = &LAB_006c5890;
      FUN_0066cb60(param_1,local_8);
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined4 *)(param_1 + 0x44) = 0;
      *(undefined4 *)(param_1 + 0x40) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  return;
}

