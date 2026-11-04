
void __fastcall FUN_00440e60(int param_1)

{
  if (*DAT_00a16698 == '\x01') {
    *(undefined1 *)(param_1 + 0xb9) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0xb9) = 0;
  }
  if (*DAT_00a16694 == '\x01') {
    *(undefined4 *)(param_1 + 0xb4) = 2;
  }
  else {
    *(undefined4 *)(param_1 + 0xb4) = 1;
  }
  if (*DAT_00a16690 == '\x03') {
    *(undefined2 *)(param_1 + 0x62) = 1;
    *(undefined2 *)(param_1 + 0x4c) = 1;
  }
  if (*DAT_00a16690 == '\x05') {
    *(undefined2 *)(param_1 + 0x62) = 2;
    *(undefined2 *)(param_1 + 0x4c) = 2;
  }
  return;
}

