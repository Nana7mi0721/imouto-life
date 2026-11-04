
undefined4 FUN_00596590(int param_1)

{
  SelectObject(DAT_00ddb2f0,DAT_00ddb2f4);
  if (**(int **)(param_1 + 0x30) != 0) {
    SelectObject(DAT_00ddb2f0,DAT_00ddb2f8);
    DAT_00ddb2f8 = (HGDIOBJ)0x0;
  }
  DeleteDC(DAT_00ddb2f0);
  return 0;
}

