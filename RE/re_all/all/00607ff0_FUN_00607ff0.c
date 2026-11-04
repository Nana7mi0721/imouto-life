
void __fastcall FUN_00607ff0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_006076b0();
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x54))(1);
    piVar1 = (int *)FUN_006076b0();
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  if (*(LPVOID *)(param_1 + 0x60) != (LPVOID)0x0) {
    VirtualFree(*(LPVOID *)(param_1 + 0x60),0,0x8000);
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  return;
}

