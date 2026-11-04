
undefined4
FUN_0066bab0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,uint *param_5,
            uint *param_6,uint *param_7,uint *param_8,uint *param_9)

{
  if ((((param_1 == 0) || (param_2 == (undefined4 *)0x0)) || (param_3 == (undefined4 *)0x0)) ||
     (((param_4 == (undefined4 *)0x0 || (param_5 == (uint *)0x0)) || (param_6 == (uint *)0x0)))) {
    return 0;
  }
  *param_3 = *param_2;
  *param_4 = param_2[1];
  *param_5 = (uint)*(byte *)(param_2 + 6);
  *param_6 = (uint)*(byte *)((int)param_2 + 0x19);
  if (param_8 != (uint *)0x0) {
    *param_8 = (uint)*(byte *)((int)param_2 + 0x1a);
  }
  if (param_9 != (uint *)0x0) {
    *param_9 = (uint)*(byte *)((int)param_2 + 0x1b);
  }
  if (param_7 != (uint *)0x0) {
    *param_7 = (uint)*(byte *)(param_2 + 7);
  }
  FUN_0066ad80(param_1,*param_2,param_2[1],*(undefined1 *)(param_2 + 6),
               *(undefined1 *)((int)param_2 + 0x19),*(undefined1 *)(param_2 + 7),
               *(undefined1 *)((int)param_2 + 0x1a),*(undefined1 *)((int)param_2 + 0x1b));
  return 1;
}

