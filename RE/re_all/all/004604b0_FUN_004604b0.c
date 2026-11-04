
undefined4 FUN_004604b0(int param_1)

{
  undefined4 uVar1;
  
  if (((*(char *)(param_1 + 1) == '\0') || (*(char *)(param_1 + 2) == '\0')) ||
     (*(char *)(param_1 + 3) == '\0')) {
    if (((*(char *)(param_1 + 1) == '\0') || (*(char *)(param_1 + 2) == '\0')) ||
       (*(char *)(param_1 + 3) != '\0')) {
      if ((*(char *)(param_1 + 1) == '\0') || (*(char *)(param_1 + 2) != '\0')) {
        if ((*(char *)(param_1 + 1) == '\0') && (*(char *)(param_1 + 2) != '\0')) {
          uVar1 = 2;
        }
        else if ((*(char *)(param_1 + 1) == '\0') && (*(char *)(param_1 + 2) == '\0')) {
          uVar1 = 0;
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 3;
    }
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}

