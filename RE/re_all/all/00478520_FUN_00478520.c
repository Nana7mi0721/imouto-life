
void __fastcall FUN_00478520(int param_1)

{
  undefined2 local_c;
  
  if (*(char *)(param_1 + 0xae) == '\0') {
    if (*(char *)(param_1 + 0x55) == '\0') {
      if (*(short *)(param_1 + 0x48) == 6) {
        local_c = 4;
      }
      else {
        local_c = 2;
      }
      *(undefined2 *)(param_1 + 0x48) = local_c;
    }
    else {
      *(undefined2 *)(param_1 + 0x48) = 1;
    }
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return;
}

