
undefined8 FUN_004fb5d0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar1 = 0;
    uVar2 = 0;
  }
  else if (*(int *)(param_1 + 0x60) == 0 && *(int *)(param_1 + 100) == 0) {
    uVar1 = 0;
    uVar2 = 0;
  }
  else {
    if ((*(int *)(param_1 + 0x38) != 0 || *(int *)(param_1 + 0x3c) != 0) &&
       ((*(int *)(param_1 + 0x38) != 0xffff || (*(int *)(param_1 + 0x3c) != 0)))) {
      if ((*(int *)(param_1 + 0x50) == *(int *)(param_1 + 0x38)) &&
         (*(int *)(param_1 + 0x54) == *(int *)(param_1 + 0x3c))) {
        uVar1 = 0;
        uVar2 = 0;
        goto LAB_004fb66b;
      }
    }
    uVar1 = *(undefined4 *)(param_1 + 0x58);
    uVar2 = *(undefined4 *)(param_1 + 0x5c);
  }
LAB_004fb66b:
  return CONCAT44(uVar2,uVar1);
}

