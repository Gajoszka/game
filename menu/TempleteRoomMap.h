#pragma once
template<typename T>
class TempleteRoomMap {
	T* data_;
	size_t width_;
	size_t height_;

public:

	TempleteRoomMap(T* ptr, size_t h, size_t w) :
		data_{ ptr },
		width_{ w },
		height_{ h }
	{}

	size_t width() const { return width_; }
	size_t height() const { return height_; }

	T& operator()(size_t h, size_t w) {
		assert(w < width_);
		assert(h < height_);
		return data_[width_ * h + w];
	}

	T const& operator()(size_t h, size_t w) const {
		return const_cast<TempleteRoomMap&>(*this)(h, w);
	}
};

