
void __fastcall FUN_00485a70(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = *(undefined1 *)(param_1 + 0xae);
  *(undefined1 *)(param_1 + 0xae) = 1;
  switch(*(undefined2 *)(param_1 + 0x48)) {
  case 1:
    FUN_00479460(0);
    break;
  case 2:
    FUN_00478b90(0);
    break;
  case 3:
    FUN_004791a0(0);
    break;
  case 4:
    FUN_00478b00(0);
    break;
  case 6:
    FUN_00478a70(0);
    break;
  case 7:
    FUN_00478ee0(0);
    break;
  case 8:
    FUN_00443aa0(0);
    break;
  case 9:
    FUN_00478c20(0);
  }
  *(undefined1 *)(param_1 + 0xae) = uVar1;
  return;
}

