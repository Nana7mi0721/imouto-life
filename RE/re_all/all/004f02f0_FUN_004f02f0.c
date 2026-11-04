
int __thiscall FUN_004f02f0(int param_1,int param_2)

{
  uint local_8;
  
  FUN_004739c0(param_2);
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_2 + 0x148);
  FUN_004d2030(param_2 + 0x14c);
  *(undefined4 *)(param_1 + 0x15c) = *(undefined4 *)(param_2 + 0x15c);
  FUN_00479af0(param_2 + 0x160);
  *(undefined4 *)(param_1 + 0x1e8) = *(undefined4 *)(param_2 + 0x1e8);
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    *(undefined1 *)(param_1 + local_8 + 0x1ec) = *(undefined1 *)(param_2 + local_8 + 0x1ec);
  }
  *(undefined1 *)(param_1 + 0x1f1) = *(undefined1 *)(param_2 + 0x1f1);
  FUN_0046f560(param_2 + 500);
  FUN_004cead0(param_2 + 0x240);
  *(undefined4 *)(param_1 + 0x250) = *(undefined4 *)(param_2 + 0x250);
  *(undefined4 *)(param_1 + 0x254) = *(undefined4 *)(param_2 + 0x254);
  *(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_2 + 600);
  *(undefined4 *)(param_1 + 0x25c) = *(undefined4 *)(param_2 + 0x25c);
  *(undefined4 *)(param_1 + 0x260) = *(undefined4 *)(param_2 + 0x260);
  return param_1;
}

