
undefined1 * __thiscall FUN_00473730(undefined1 *param_1,undefined1 *param_2)

{
  uint local_8;
  
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  param_1[0xc] = param_2[0xc];
  param_1[0xd] = param_2[0xd];
  param_1[0xe] = param_2[0xe];
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_2 + 0x24);
  FUN_004d2030(param_2 + 0x28);
  for (local_8 = 0; local_8 < 500; local_8 = local_8 + 1) {
    *(undefined4 *)(param_1 + local_8 * 4 + 0x38) = *(undefined4 *)(param_2 + local_8 * 4 + 0x38);
  }
  *(undefined4 *)(param_1 + 0x808) = *(undefined4 *)(param_2 + 0x808);
  FUN_004cead0(param_2 + 0x80c);
  FUN_004cf8f0(param_2 + 0x81c);
  *(undefined4 *)(param_1 + 0x82c) = *(undefined4 *)(param_2 + 0x82c);
  FUN_004f09c0(param_2 + 0x830);
  FUN_004f09c0(param_2 + 0x840);
  param_1[0x850] = param_2[0x850];
  *(undefined4 *)(param_1 + 0x854) = *(undefined4 *)(param_2 + 0x854);
  *(undefined4 *)(param_1 + 0x858) = *(undefined4 *)(param_2 + 0x858);
  *(undefined4 *)(param_1 + 0x85c) = *(undefined4 *)(param_2 + 0x85c);
  *(undefined4 *)(param_1 + 0x860) = *(undefined4 *)(param_2 + 0x860);
  FUN_004cb840(param_2 + 0x864);
  *(undefined4 *)(param_1 + 0x880) = *(undefined4 *)(param_2 + 0x880);
  *(undefined4 *)(param_1 + 0x884) = *(undefined4 *)(param_2 + 0x884);
  *(undefined4 *)(param_1 + 0x888) = *(undefined4 *)(param_2 + 0x888);
  *(undefined4 *)(param_1 + 0x88c) = *(undefined4 *)(param_2 + 0x88c);
  *(undefined4 *)(param_1 + 0x890) = *(undefined4 *)(param_2 + 0x890);
  *(undefined4 *)(param_1 + 0x894) = *(undefined4 *)(param_2 + 0x894);
  *(undefined4 *)(param_1 + 0x898) = *(undefined4 *)(param_2 + 0x898);
  *(undefined4 *)(param_1 + 0x89c) = *(undefined4 *)(param_2 + 0x89c);
  *(undefined4 *)(param_1 + 0x8a0) = *(undefined4 *)(param_2 + 0x8a0);
  param_1[0x8a4] = param_2[0x8a4];
  return param_1;
}

