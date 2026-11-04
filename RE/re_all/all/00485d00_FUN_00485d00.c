
void __fastcall FUN_00485d00(int param_1)

{
  if (*(char *)(param_1 + 0x55) == '\0') {
    switch(*(undefined2 *)(param_1 + 0x48)) {
    case 2:
      FUN_004785a0();
      break;
    case 4:
      FUN_00478700();
      break;
    case 6:
      FUN_004784f0();
      break;
    case 8:
      FUN_00478650();
    }
  }
  else {
    switch(*(undefined2 *)(param_1 + 0x48)) {
    case 1:
      FUN_004785a0();
      break;
    case 2:
      FUN_00478520();
      break;
    case 3:
      FUN_004784f0();
      break;
    case 4:
      FUN_004785d0();
      break;
    case 6:
      FUN_00478730();
      break;
    case 7:
      FUN_00478700();
      break;
    case 8:
      FUN_00478680();
      break;
    case 9:
      FUN_00478650();
    }
  }
  return;
}

