
undefined4 __thiscall
FUN_00609800(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int param_6)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 != 1) {
    return 0x80070057;
  }
  if (param_6 == 0) {
    return 0x80004003;
  }
  *(int *)(param_1 + 0xfc) = param_6;
  iVar1 = *(int *)(param_1 + 0xe8);
  *(undefined4 *)(param_1 + 0xec) = 1;
  *(undefined4 *)(param_1 + 0xf0) = param_3;
  *(undefined4 *)(param_1 + 0xf4) = param_4;
  *(undefined4 *)(param_1 + 0xf8) = param_5;
  if (iVar1 != 0) {
    (**(code **)(*(int *)(iVar1 + 0xc) + 8))(iVar1 + 0xc);
    *(undefined4 *)(param_1 + 0xe8) = 0;
  }
  param_6 = 0;
  puVar2 = operator_new(0x68);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_00607ce0(s_SampleGrabberAllocator_00a06124,0,&param_6);
    puVar2[0x19] = param_1;
    *puVar2 = &PTR_LAB_00803d7c;
    puVar2[3] = &PTR_LAB_00803d50;
  }
  *(undefined4 **)(param_1 + 0xe8) = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  (**(code **)(puVar2[3] + 4))(puVar2 + 3);
  return param_5;
}

