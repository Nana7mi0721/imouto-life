
float10 FUN_00540830(ushort param_1)

{
  if (param_1 == 0) {
    return (float10)0;
  }
  return (float10)(float)(((param_1 & 0xffff8000) * 8 | param_1 & 0x3ff) << 0xd |
                         ((param_1 >> 10 & 0x1f) + 0x70) * 0x800000);
}

