
/* Library Function - Single Match
    public: virtual __thiscall std::ios_base::~ios_base(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall std::ios_base::~ios_base(ios_base *this)

{
  void *_Memory;
  
  *(undefined ***)this = &PTR_FUN_007d4774;
  if ((*(int *)(this + 4) == 0) ||
     ((&DAT_00a200dc)[*(int *)(this + 4)] = (&DAT_00a200dc)[*(int *)(this + 4)] + -1,
     (char)(&DAT_00a200dc)[*(int *)(this + 4)] < '\x01')) {
    _Tidy(this);
    _Memory = *(void **)(this + 0x24);
    if (_Memory != (void *)0x0) {
      FUN_004d3d00();
      _free(_Memory);
    }
  }
  return;
}

